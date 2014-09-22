#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
public:
	void enQueue(int x){
		st1_.emplace(x);
	}
	int deQueue(){
		if(st2_.empty()){
			while(!st1_.empty()){
				st2_.emplace(st1_.top());
				st1_.pop();
			}
		}
		if(!st2_.empty()){
			int res = st2_.top();
			st2_.pop();
			return res;
		}
		throw invalid_argument("error");
	}
private:
	stack<int> st1_, st2_;
};