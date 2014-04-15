#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 字符串是否包含问题

// 假设这有两个分别由字母组成的字符串A另外字符串B，字符串B的字母数较字符串A少一些。什么方法能最快地查出字符串B所有字母是不是都在字符串A里？也就是说判断字符串B是不是字符串A的真子集（为了简化，姑且认为两个集合都不是空集，即字符串都不为空。）。为了简单起见，我们规定输入的字符串只包含大写英文字母。


/*
 Solution #1. 暴力轮询.
 最直观也是最简单的思路是，针对string2中每一个字符，一一与string1中每个字符依次轮询比较，看它是否在String1中
 */

bool compare(string &a, string &b)
{
	for(int i = 0; i < b.length(); i++) {
		int j; //计数器.
		for(j = 0; j < a.length() && a[j] != b[i]; j++)
			;
		if(j >= a.length())
		{
			return false;
		}
	}
	return true;
}


/*
 Solution #2. 普通排序.利用C++库函数sort, O(nlogn); 随后做线性扫描O(m+n),因为已经排好序
 */
bool compare(string &a, string &b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int pa = 0, pb = 0; pb < b.length; )
	{
		while( pa < a.length() && b[pb] < a[pa])
			pa++;
		if( pa >= a.length() || a[pa] > b[pb] )
			return false;
		pb++;
	}
	return true;
}


/*
 Solution #3. 计数比较.  O(m+n)
 */
bool compare(string &a, string &b)
{
	vector<int> have;
	have.resize(127,0); // ASCII码共有127位
	
	for(int i = 0; i < a.length(); i++)
		have[a[i]]++;
	for(int j = 0; j < b.length(); j++)
		if(have[b[j]] == 0)
			return false;
	
	return true;	
}


/*
 Solution #4. 妙用hashtable.  O(m+m)
 */
bool compare(string &a, string &b)
{
	vector<int> hash;
	hash.resize(127,0);
	int m = 0; // 表示b中有几个unique的符号
	
	for(int i = 0; i < b.length(); i++)
	{
		int pos = b[i];
		if(hash[pos] == 0)
		{
			hash[pos] = 1;
			m++;
		}
	}
	for(int i = 0; i < a.length() && m > 0; i++)
	{
		int pos = a[i];
		if(hash[pos] == 1)
		{
			m--;
			hash[pos] = 0;
		}
	}
	return m==0;
}



/*
 Solution #5. 素数乘积, 最快达到O(n)
 这个方法的缺点在于, 相乘后的数字可能很大,溢出.
 */
bool compare(string &a, string &b)
{
	const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,61, 67, 71, 73, 79, 83, 89, 97, 101};
	int f = 1;
	    for (int i = 0; i < a.length(); ++i)
	    {
	        int x = p[a[i] - 'A'];
	        if (f % x)
	        {
	            f *= x;
	        }
	    }
	    for (int i = 0; i < b.length(); ++i)
	    {
	        int x = p[b[i] - 'A'];
	        if (f % x)
	        {
	            return false;
	        }
	    }
	    return true;
	}
}

