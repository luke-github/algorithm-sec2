#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Interval{
	int left,right;
};

struct leftcmp{
	bool operator () (Interval a, Interval b) const {
		return a.left != b.left ? a.left < b.left : a.right<b.right;
	}
};

struct rightcmp{
	bool operator () (Interval a, Interval b) const{
		return a.right != b.right ? a.right<b.right : a.left < b.left;
	}
};

vector<int> min_visits(vector<Interval> vec){
	set<Interval,leftcmp> leftset;
	set<Interval,rightcmp> rightset;
	for(Interval I : vec){
		leftset.emplace(I);
		rightset.emplace(I);
	}
	vector<int> res;
	while(!leftset.empty() && !rightset.empty()){
		int b = rightset.begin()->right;
		res.emplace_back(b);
		auto it = leftset.begin();
		while(it!=leftset.end() && it->left<=b){
			leftset.erase(*it);
			rightset.erase(*it);
			it++;
		}
	}
	return res;
}