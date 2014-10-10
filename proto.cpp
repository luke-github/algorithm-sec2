#include <iostream>
#include <vector>
using namespace std;

int min_steps(string s1, string s2){
	int len1 = s1.size();
	int len2 = s2.size();
	vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
	for(int i=0;i<=len1;i++){
		dp[i][0]=i;
	}
	for(int j=0;j<=len2;j++){
		dp[0][j]=j;
	}
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
			}
		}
	}
	return dp[len1][len2];
}

int main(){
	cout<<min_steps("abc","aec");
}