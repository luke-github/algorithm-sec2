#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	priority_queue<int,vector<int>,greater<int>> max_queue;
	max_queue.emplace(13);
	max_queue.emplace(123);
	max_queue.emplace(33);
	max_queue.emplace(122);
	max_queue.emplace(19);
	while(!max_queue.empty()){
		cout<<max_queue.top()<<endl;
		max_queue.pop();
	}

}