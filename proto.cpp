#include <iostream>
#include <vector>
using namespace std;

int max_choice_handler(vector<int>& vec, int a, int b, vector<vector<int>>& dp){
	if(a>b){
		return 0;
	}
	if(dp[a][b]==-1){
		dp[a][b] = max( vec[a] + min(max_choice_handler(vec,a+1,b-1,dp),max_choice_handler(vec,a+2,b,dp)),
						vec[b] + min(max_choice_handler(vec,a+1,b-1,dp),max_choice_handler(vec,a,b-2,dp))
							);
	}
	return dp[a][b];
}

int max_choice(vector<int>& vec){
	vector<vector<int>> dp(vec.size(),vector<int>(vec.size(),-1));
	return max_choice_handler(vec,0,vec.size()-1,dp);
}