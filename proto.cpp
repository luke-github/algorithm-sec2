#include <iostream>
using namespace std;

string conversion(const string& str, int b1, int b2){
	string res;
	bool neg = str.front()=='-';
	int num = 0;
	for(int i = (neg?1:0);i<str.size();i++){
		num *= b1;
		num += isdigit(str[i])?str[i]-'0':str[i]-'A'+10;
	}
	while(num){
		int k = num % b2;
		res.push_back(k>=10?'A'+k-10:'0'+k);
		num /= b2;
	}
	if(res.empty()){
		res.push_back(0);
	}
	if(neg){
		res.push_back('-');
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	cout<<conversion("1024",10,2);
}