#include <iostream>
#include <vector>
using namespace std;

int stringtoint(string s){
	bool is_negative = false;
	int res = 0;
	if(s[0]=='-'){
		is_negative = true;
	}
	for(int i = is_negative;i<s.size();i++){
		res = res*10;
		res += s[i] - '0';
	}
	if(is_negative){
		res = -res;
	}
	return res;
}

string inttostring(int x){
	bool is_negative = false;
	string res;
	if(x<0){
		x=-x;
		is_negative = true;
	}
	while(x){
		res.push_back(x%10+'0');
		x /= 10;
	}
	if(res.empty()){
		res.push_back('0');
	}
	if(is_negative){
		res.push_back('-');
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	cout<<stringtoint("123")<<endl;
	cout<<inttostring(123)<<endl;
}