#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


//第一章：左旋转字符串

//定义字符串左旋转操作:把字符串前面的若干个字符移动到字符串尾部,如把字符串 abcdef 左旋转 2 位得到字符串 cdefab。请实现字符串左旋转的函数,要求对长度为 n 的字符串操作的时间复杂度为 O(n),空间复杂度为 O(1)。


/* 
 Solution #1. Hardwork.
 */

void left_shift_one(char *s, int n)
{
	assert(s != NULL);
	char t = s[0];
	for(int i = 1; i < n; i++)
		s[i-1] = s[i];
	s[n-1] = t;
}

void left_shift_m(char *s, int n, int m)
{
	while(m--)
		left_shift_one(s, n);
}




/* 
 Solution #2. 3-step reverse method. (X'Y')' = YX
 */

void reverse(char *s, int from, int to)
{
	// 镜面翻转
	while(from < to)
	{
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}

void leftshift(char *s, int n, int m)
{
	m %= n;
	reverse(s, 0, m-1);
	reverse(s, m, n-1);
	reverse(s, 0, n-1);
}




int main()
{
	char test[] = "abcdefg";
	cout<<test<<endl;
	left_shift_m(test, strlen(test), 2);
	cout<<test<<endl;
	
	return 0;
}