#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare{
	bool operator()(const pair<int,int> l, const pair<int,int> r){
		return l.second < r.second;
	}
};

vector<int> k_large_element(vector<int> A, int k){
	priority_queue<pair<int,int>,vector<pair<int,int>>,compare> max_queue;
	vector<int> res;
	max_queue.emplace(0,A[0]);
	for(int i=0;i<k;i++){
		pair<int,int> cur = max_queue.top();
		int index = cur.first;
		res.emplace_back(cur.second);
		max_queue.pop();
		if(((index<<1)+1)<A.size()){
			max_queue.emplace((index<<1)+1,A[(index<<1)+1]);
		}
		if(((index<<1)+2)<A.size()){
			max_queue.emplace((index<<1)+2,A[(index<<1)+2]);
		}
	}
	return res;
}