#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



class myVector()
{
private:
	vector<vector<int>> container;
public:
	myVector() {};
	
	void new(int id) {
		container.push_back(id);
	}
	
	void add(int id, int num) {
		container[id].push_back(num);
	}
	
	void merge(int id1, int id2) {
		for(int i = 0; i <= container[id2].size(); i++)
			container[id1].push_back(container[id2][i]);
		container[id2].clear();
	}
	
	void unique(int id) {
		sort(container[id].begin(), container[id].end());
		for(vector<int>::const_iterator itr = container[id].begin(); itr < container[id].end(); itr++) {
			if( *itr+1 == *itr)
				container[id].erase(itr+1);
		}
	}
	
	void out(int id) {
		sort(container[id].begin(), container[id].end());
		for(int i = 0; i < container[id].size(); i++)
			cout << container[id][i] <<" ";
		cout << endl;
	}
	
};



int main()
{
    int n;
	cin >> n;
	
	myVector a;
	
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
		
		cout << p <<endl;
		
		while(p) {
			printf("%s",p);
			p = strtok(NULL, split);
		}
		
	}
	
	
	
	
	
    return 0;
}