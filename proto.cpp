#include <iostream>
#include <stack>
using namespace std;

class My_Stack{
public:
	bool empty(){
		return st_.empty();
	}
	int max_element(){
		if(empty()){
			throw invalid_argument("invalid");
		}
		return st_.top().second;
	}
	void push(int x){
		st_.emplace(x,max(x,st_.empty()?x:st_.top().second));
	}
	int pop(){
		if(empty()){
			throw invalid_argument("invalid");
		}
		int res = st_.top().first;
		st_.pop();
		return res;
	}
private:
	stack<pair<int,int>> st_;
};