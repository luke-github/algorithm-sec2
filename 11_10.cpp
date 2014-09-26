#include <iostream>
#include <queue>
using namespace std;

struct compare{
	bool operator() (const pair<int,int> l, const pair<int,int> r){
		return l.first <  r.first;
	}
};

class MyStack{
public:
	void push(int x){
		q_.emplace(order_++,x);
	}
	int pop(){
		int res = q_.top().second;
		q_.pop();
		return res;		
	}
	int peek(){
		return q_.top().second;
	}
private:
	int order_=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,compare> q_;
};

class MyQueue{
public:
	void enqueue(int x){
		q_.emplace(order_--,x);
	}
	int dequeue(){
		int res = q_.top().second;
		q_.pop();
		return res;
	}
	int peek(){
		return q_.top().second;
	}
private:
	int order_=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,compare> q_;
};