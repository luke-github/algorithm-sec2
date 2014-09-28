#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct compare{
	bool operator () (int* a, int* b) const{
		return *a < *b;
	}
};

void sort_text(string filename){
	ifstream file(filename);
	vector<int> vec;
	int x;
	while(file>>x){
		vec.emplace_back(x);
	}
	vector<int*> p;
	for(int x : vec){
		p.emplace_back(&x);
	}
	sort(p.begin(),p.end());
	for(int* x : p){
		cout<<*x<<endl;
	}
}