#include <iostream>
#include <vector>
using namespace std;

vector<int> grey_code_algorithm(int n){
	if(n==0){
		return {0};
	}
	if(n==1){
		return {0,1};
	}
	auto pre_res = grey_code_algorithm(n-1);
	int prefix = 1<<(n-1);
	vector<int> res;
	for(int i=pre_res.size()-1;i>=0;i--){
		res.emplace_back(prefix+pre_res[i]);
	}
	pre_res.insert(pre_res.end(),res.begin(),res.end());
	return pre_res;
}

string dtob(int x){
	string res;
	while(x){
		res.push_back('0'+ (x&1));
		x = x>>1;
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	auto res = grey_code_algorithm(3);
	for(int x : res){
		cout<<dtob(x)<<" ";
	}
	// cout<<dtb(3);
}