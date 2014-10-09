#include <iostream>
#include <vector>
using namespace std;

void combination_algo_handler(int n, int k, int index, vector<int>& ans, vector<vector<int>>& res){
	if(ans.size() == k){
		res.emplace_back(ans);
		return;
	}
	if(k - ans.size() <= n - (index+1)){
		combination_algo_handler(n,k,index+1,ans,res);
	}
	ans.emplace_back(index+1);
	combination_algo_handler(n,k,index+1,ans,res);
	ans.pop_back();
}

vector<vector<int>> combination_algo(int n, int k){
	vector<vector<int>> res;
	vector<int> ans;
	combination_algo_handler(n,k,0,ans,res);
	return res;
}

int main(){
	auto res = combination_algo(5,2);
	for(auto vec : res){
		for(int x : vec){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}