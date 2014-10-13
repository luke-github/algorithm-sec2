#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
using namespace std;

struct HashTuple{
	int operator ()(const tuple<int,int,int>& t){
		return hash<int>()(get<0>(t)) ^ hash<int>()(get<1>(t)) ^ hash<int>()(get<2>(t));
	}
};


struct TestA{
	int operator () (const int n, const int m) {
		return m*n;
	}
};

int main(){
	TestA a;
	cout<<a(2,4);
}
