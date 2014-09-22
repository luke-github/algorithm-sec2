#include <iostream>
#include <stack>
using namespace std;

void insert(int m, stack<int>* s){
	if(s->empty() || m>=s->top()){
		s->push(m);
	}else{
		int h = s->top();
		s->pop();
		insert(m,s);
		s->push(h);
	}
}

void sort_stack(stack<int>* s){
	if(!s->empty()){
		int m = s->top();
		s->pop();
		sort_stack(s);
		insert(m,s);
	}
}

int main(){
	stack<int> in;
	in.push(1);
	in.push(9);
	in.push(4);
	in.push(7);
	sort_stack(&in);
	while(!in.empty()){
		cout<<in.top();
		in.pop();
	}
}