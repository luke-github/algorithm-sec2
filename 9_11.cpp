#include <iostream>
#include <vector>
using namespace std;

class MyQueue{
public:
	MyQueue(int size) : data_(size) {}
	
	void enQueue(int x){
		if(count_==data_.size()){
			rotate(data_.begin(),data_.begin()+head_,data_.end());
			data_.resize(data_.size()<<1);
			head_=0;
			tail_=count_;
		}
		data_[tail_] = x;
		tail_ = (tail_+1)%data_.size();
		count_++;
	}

	int deQueue(){
		if(!count_){
			throw invalid_argument("empty");
		}
		int res = data_[head_];
		head_ = (head_+1)%data_.size();
		count_--;
		return res;
	}

	int size(){
		return count_;
	}
private:
	vector<int> data_;
	int head_=0,tail_=0,count_=0;
};