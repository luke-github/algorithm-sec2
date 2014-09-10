#include <iostream>
#include <vector>
using namespace std;

string intToString(int x){
	string res;
	bool is_negative =  false;
	if(x<0){
		is_negative = true;
		x = -x;
	}
	while(x){
		res.push_back('0'+x%10);
		x = x/10;
	}
	if(res.empty()){
		res.push_back('0');
	}
	reverse(res.begin(),res.end());
	return res;
}

int stringToin(string x){
	bool is_negative = false;
	int res = 0;
	for(int i = is_negative;i<x.size();i++){
		res = res * 10;
		res += x[i] - '0';
	}
	if(is_negative){
		res = -res;
	}
	return res;
}

int main(){
	cout<<stringToin("123")<<endl;
	cout<<intToString(456)<<endl;
}