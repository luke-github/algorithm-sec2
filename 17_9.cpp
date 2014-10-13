#include <iostream>
#include <vector>
#include <complex>
#include <numeric>
using namespace std;

int n_sum(vector<int>& vec,int k){
	int sum = accumulate(vec.begin(),vec.end(),0);
	vector<vector<int>> dp(vec.size()+1,vector<int>(sum+1,0));
	if(sum&1){
		return -1;
	}
	dp[0][0]=1;
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<=sum;j++){
			dp[i+1][j] = dp[i][j] + (vec[i]>j?0:dp[i][j-vec[i]]);
		}
	}
	return dp[vec.size()][k];
}

int main(){
	vector<int> in = {1,2,2,3,4};
	cout<<n_sum(in,4);
}