#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int min_parlidrome(string s){
	vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
	vector<int> res(s.size()+1);
	iota(res.rbegin(),res.rend(),-1);
	for(int i=s.size()-1;i>=0;i--){
		for(int j=i;j<s.size();j++){
			if(s[i]==s[j] && (j-i<2 || dp[i+1][j-1])){
				dp[i][j]=true;
				res[i] = min(res[i],1+res[j+1]);
			}
		}
	}
	return res[0];
}

int main(){
	cout<<min_parlidrome("aabbccbb");
}