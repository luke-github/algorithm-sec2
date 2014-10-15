#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> check_makeup(unordered_set<string>& dict, string str){
	vector<string> res;
	vector<int> dp(str.size(),0);
	for(int i=0;i<str.size();i++){
		if(dict.find(str.substr(0,i+1))!=dict.end()){
			dp[i] = i+1;
		}
		for(int j=0;j<i&&dp[i]==0;j++){
			if(dp[j]&&dict.find(str.substr(j+1,i-j))!=dict.end()) {
				dp[i]=i-j;
			}
		}
	}
	if(dp.back()){
		int index = str.size()-1;
		while(index>=0){
			res.emplace_back(str.substr(index - dp[index] + 1,dp[index]));
			index -= dp[index];
		}
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	unordered_set<string> in = {"abc","123","dd"};
	auto res = check_makeup(in,"dd123abcabc");
	for(string x : res){
		cout<<x<<" ";
	}
}