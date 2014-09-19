#include <iostream>
#include <stack>
using namespace std;

class My_Stack{
public:
	bool empty(){
		return st_.empty();
	}
	int max_element(){
		if(!empty()){
			return st_.top().second;
		}
		throw invalid_argument("invalid");
	}
	void push(int x){
		st_.emplace(x,max(x,st_.empty()?x:st_.top().second));
	}
	int pop(){
		if(!empty()){
			int res = st_.top().first;
			return res;
		}
		throw invalid_argument("invalid");
	}
private:
	stack<pair<int,int>> st_;
};

int main(){
	My_Stack ms;
	ms.push(1);
	ms.push(3);
	ms.push(2);
	ms.push(9);
	cout<<ms.max_element();
}