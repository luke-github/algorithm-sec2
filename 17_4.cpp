#include <iostream>
#include <vector>
using namespace std;

int num_ways(int n, int m){
	if(n < m){
		swap(n,m);
	}
	vector<vector<int>> dp(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		dp[i][0]=1;
	}
	for(int i=0;i<m;i++){
		dp[0][i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[n-1][m-1];
}

int num_ways_obstacle(int n, int k, vector<vector<int>>& vec){
	vector<vector<int>> dp(n,vector<int>(k,0));
	if(vec[0][0]==1){
		return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			if(vec[i][j]==0){
				dp[i][j] += (i<1?0:dp[i-1][j]) + (j<1?0:dp[i][j-1]);
			}
		}
	}
	return dp[n-1][k-1];
}

int main(){
	// cout<<num_ways(3,5);
	vector<vector<int>> in(3,vector<int>(3,0));
	in[2][1]=1;
	cout<<num_ways_obstacle(3,3,in);
}