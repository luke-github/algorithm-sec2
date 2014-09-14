#include <iostream>
#include <vector>
using namespace std;

string decimal_to_binary(int num){
	string res;
	while(num){
		res.push_back('0'+(num&1));
		num >>= 1;
	}
	reverse(res.begin(),res.end());
	return res;
}

int binary_to_decimal(string num){
	int res;
	for(int i=0;i<num.size();i++){
		res = res*2 + num[i]-'0';
	}
	return res;
}

string encode(vector<int>& vec){
	string res;
	for(int x : vec){
		string cur_res = decimal_to_binary(x);
		cur_res.insert(0,cur_res.size()-1,'0');
		res += cur_res;
	}
	return res;
}

vector<int> decode(string str){
	vector<int> res;
	int index = 0;
	while(index<str.size()){
		int zero_index = index;
		while(zero_index<str.size() && str[zero_index]=='0'){
			zero_index++;
		}
		int len = zero_index - index + 1;
		res.emplace_back(binary_to_decimal(str.substr(zero_index,len)));
		index = zero_index + len;
	}
	return res;
}

int main(){
	vector<int> in = {12};
	cout<<encode(in)<<endl;
	vector<int> res = decode(encode(in));
	for(int x : res){
		cout<<x<<endl;
	}
}
