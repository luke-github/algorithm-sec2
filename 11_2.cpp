#include <iostream>
#include <vector>
using namespace std;

vector<int> increasing_decreasing_sort(vector<int> vec){
	bool is_increase = true;
	vector<vector<int>> res;
	int index = 0;
	int start = 0;
	while(index<vec.size()){
		if((vec[index]<vec[index+1]&&!is_increase)
			||(vec[index]>=vec[index+1]&&is_increase)){
			if(is_increase){
				res.emplace_back(vec.cbegin()+start,vec.cbegin()+index);
			}else{
				res.emplace_back(vec.crbegin()+vec.size()-index,vec.crbegin()+vec.size()-start);
			}
			start = index;
			is_increase = !is_increase;
		}
		index++;
	}
	if(start<vec.size()){
		if(is_increase){
			res.emplace_back(vec.cbegin()+start,vec.cend());
		}else{
			res.emplace_back(vec.crbegin(),vec.crbegin()+vec.size()-start);
		}
	}
	return merge_array(res);
}