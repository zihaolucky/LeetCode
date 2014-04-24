#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <istream>
using namespace std;



void split(char buf[])
{
	int len = sizeof(buf);
	int split_pos = 0;
	
	while(buf[split_pos] != ' ')
		split_pos++;
	
	
	
}


int main()
{
    vector<int> a(5);
	for(int i = 0; i < 5; i++)
		a[i] = 5-i;
	for(int i = 0; i < 5; i++)
		cout<<a[i]<<",";
	cout<<endl;
	
	
	
	sort(a.begin(), a.end());
	a.insert(a.begin(), 1);
	
	for(int i = 0; i < a.size(); i++)
		cout<<a[i]<<",";
	cout<<endl;
	
	a.erase(a.begin()+1);
	for(int i = 0; i < a.size(); i++)
		cout<<a[i]<<",";
	cout<<endl;
	
	
	
	
    
	int input_times;
	cin >> input_times;
	
	char buf[input_times][100];
	
	
	int *num;
	for(int i = 0; i <= input_times; i++) {
		cin.getline(buf[i], 100);
	}
	
	
	const char *split = " ";
	char *p;
	for(int i = 0; i <= input_times; i++) {
		p = strtok(buf[i], split);
		
			
	}
	
	
		
	
	
	
	
	
	return 0;
}