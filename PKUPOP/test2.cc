#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;


// 函数对象



template<typename _InputIterator, typename _Tp, typename _BinaryOperation>
_Tp Accumulate(_InputIterator __first, _InputIterator __last, _Tp __init, _BinaryOperation __binary_op)
{
	for(; __first != __last; ++__first)
		__init = __binary_op(__init, *__first);
	
	return __init;
}



int SumSquares(int total, int value)
{
	return total + value * value;
}

template<class T>
void PrintInterval(T first, T last)
{
	for(; first != last; first++)
		cout << *first << " ";
	cout << endl;
}

template<class T>
class SumPowers
{
private:
	int power;
public:
	SumPowers(int p):power(p) {}
	const T operator() (const T& total, const T& value)
	{
		T v = value;
		for(int i = 0; i < power-1; i++)
			v = v * value;
		return total + v;
	}
	
};


int main()
{
	const int SIZE = 10;
	int a1[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v(a1, a1+SIZE);
	cout << "1) ";
	PrintInterval(v.begin(), v.end());
	int result = Accumulate(v.begin(), v.end(), 0, SumSquares);
	
	cout << "2) 平方和: " << result << endl;
	
	result = Accumulate(v.begin(), v.end(), 0, SumPowers<int>(3));
	cout << "3) 立方和: " << result << endl;
	
	result = Accumulate(v.begin(), v.end(), 0, SumPowers<int>(4));
	cout << "4) 4次方和: " << result << endl;
	
}


// int result = accumulate(v.begin(), v.end(), 0, SumSquares);
int accumulate(vector<int>::iterator first, vector<int>::iterator last, 
		int init, int (* op)(int, int))
{
	for(; first != last; first++)
		init = op(init, *first);
	return init;
}
			
		