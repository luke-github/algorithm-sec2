#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int cap_algorithm(vector<int> vec, int buget){
	sort(vec.begin(),vec.end());
	vector<int> cost;
	partial_sum(vec.begin(),vec.end(),back_inserter(cost));
	vector<int> hlep_vec;
	for(int i=0;i<vec.size();i++){
		hlep_vec.emplace_back(cost[i]+(vec.size()-1-i)*vec[i]);
	}
	auto it = lower_bound(hlep_vec.begin(),hlep_vec.end(),buget);
	if(it==hlep_vec.end()){
		return -1;
	}
	if(it==hlep_vec.begin()){
		return buget/vec.size();
	}
	int index = distance(hlep_vec.begin(),it)-1;
	return vec[index] + (buget - hlep_vec[index])/(vec.size() - index -1n);
}