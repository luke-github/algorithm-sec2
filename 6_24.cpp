#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascal_triangle(int n){
	vector<vector<int>> res;
	res.emplace_back(vector<int>{1});
	for(int i=1;i<n;i++){
		vector<int> cur_row;
		cur_row.emplace_back(1);
		for(int j=1;j<i;j++){
			cur_row.emplace_back(res.back()[j-1]+res.back()[j]);
		}
		cur_row.emplace_back(1);
		res.emplace_back(cur_row);
	}
	return res;
}

int main(){
	auto res = pascal_triangle(10);
	for(auto vec : res){
		for(auto x : vec){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}