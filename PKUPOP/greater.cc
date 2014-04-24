#include <iostream>
#include <list>
using namespace std;

class MyLess 
{
public:
	// 谁的个位数小,就算小
	bool operator() (const int &c1, const int &c2)
	{
		return (c1 %10) < (c2 % 10);
	}
};

template<class T>
void Print(T first, T last)
{
	for(; first != last; first++)
		cout << *first << ",";
	cout << endl;
}

int main()
{
	const int SIZE = 5;
	int a[SIZE] = {5,21,14,2,3};
	list<int> lst(a, a+SIZE);
	
	lst.sort(MyLess());	//函数对象,具体说是按照MyLess中的()运算符定义大小
	Print(lst.begin(), lst.end());
	
	lst.sort();
	Print(lst.begin(), lst.end());
	
	lst.sort(greater<int>());	//类模版->类->对象. greater<int>()是类对象
	Print(lst.begin(), lst.end());
	
	
	return 0;
}


/* greater 函数对象类模版

template<Class T>
struct greater::public binary_function<T, T, bool> {
	bool operator() (const T &x, const T &y)
		return x > y;
};
*/
