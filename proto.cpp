#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare{
	bool operator() (const pair<int,int> l, const pair<int,int> r){
		return l.first > r.first;
	}
};

// struct compare{
// 	bool operator() (const pair<int,int> l, const pair<int,int> r){
// 		return l.first > r.first;
// 	}
// };

vector<int> merge_algo(vector<vector<int>> s){
	vector<int> res;
	priority_queue<pair<int,int>, vector<pair<int,int>>,compare> min_queue;
	vector<int> vec_index;
	for(int i=0;i<s.size();i++){
		min_queue.emplace(s[i][0],i);
		vec_index[i]=1;
	}
	while(!min_queue.empty()){
		pair<int,int> cur = min_queue.top();
		res.emplace_back(cur.first);
		if(vec_index[cur.second]<s[cur.second].size()){
			min_queue.emplace(s[cur.second][vec_index[cur.second]++],cur.second);
		}
		min_queue.pop();
	}
	return res;
}