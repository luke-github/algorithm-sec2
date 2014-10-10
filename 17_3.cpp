#include <iostream>
#include <vector>
using namespace std;

int compute_alo(int n, int k){
	int dp[n+1][k+1];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=1;
		for(int j=1;j<=k && j<=i ;j++){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][k];
}


int BC_algorithm_2(int n, int k){
	int table[n+1][k+1];
	table[0][0]=1;
	for(int i=1;i<=n;i++){
		table[i][0]=1;
		for(int j=1;j<=k&&j<=i;j++){
			table[i][j]=table[i-1][j]+table[i-1][j-1];
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	return table[n][k];
}

int main(){
	cout<<compute_alo(4,3)<<endl;
	cout<<endl;
	// cout<<BC_algorithm_2(4,2)<<endl;
}