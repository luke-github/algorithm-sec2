#include <iostream>
#include <vector>
using namespace std;

bool checkInterleaving(string s1,string s2,string s3){
	vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1,false));
	dp[0][0]=true;
	if(s3.size()!=s1.size()+s2.size()){
		return false;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]==s3[i]){
			dp[i+1][0]=true;
		}else{
			break;
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]==s3[i]){
			dp[0][i+1]=true;
		}else{
			break;
		}
	}
	for(int i=0;i<s1.size();i++){
		for(int j=0;j<s2.size();j++){
			dp[i+1][j+1] = (dp[i][j+1] && s1[i]==s3[i+j+1]) || (dp[i+1][j] && s2[j]==s3[i+j+1]);
		}
	}
	return dp[s1.size()][s2.size()];
}

int main(){
	cout<<checkInterleaving("abc","123","a12bc3");
}