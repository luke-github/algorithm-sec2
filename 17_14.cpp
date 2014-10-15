#include <iostream>
#include <vector>
using namespace std;

int min_path(vector<vector<int>>& vec){
	vector<int> pre_row(vec.front());
	for(int i=1;i<vec.size();i++){
		vector<int> cur_row(vec[i]);
		cur_row.front() = cur_row.front() + pre_row.front();
		for(int j=1;j<cur_row.size()-1;j++){
			cur_row[j] += min(pre_row[j-1],pre_row[j]);
		}
		cur_row.back() += pre_row.back();
		pre_row.swap(cur_row);
	}
	return *min_element(pre_row.begin(),pre_row.end());
}