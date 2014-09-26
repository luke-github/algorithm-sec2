#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

void almost_sorted_algorithm(istringstream *sin, int k){
	priority_queue<int,vector<int>,greater<int>> min_queue;
	int x;
	for(int i=0;i<k;i++){
		*sin>>x;
		min_queue.emplace(x);
	}
	while(*sin>>x){
		min_queue.emplace(x);
		cout<<min_queue.top()<<endl;
		min_queue.pop();
	}
	while(!min_queue.empty()){
		cout<<min_queue.top()<<endl;
		min_queue.pop();
	}
}