#include <iostream>
#include <vector>
using namespace std;

int nk_algorithm(int n, int k){
	int dp[n+1][k+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=1;
		for(int j=1;j<=k && j<=i;j++){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
	return dp[n][k];
}

int main(){
	cout<<nk_algorithm(4,3);
}