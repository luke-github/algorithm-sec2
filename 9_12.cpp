#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
public:
	void enQueue(int x){
		st1_.emplace(x);
	}

	int deQueue(){
		if(!st2_.empty()){
			int res = st2_.top();
			st2_.pop();
			return res;
		}else{
			while(!st1_.empty()){
				st2_.emplace(st1_.top());
				st1_.pop();
			}
			int res = st2_.top();
			st2_.pop();
			return res;
		}
	}
private:
	stack<int> st1_, st2_;
};

int main(){
	MyQueue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
}