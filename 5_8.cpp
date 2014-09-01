#include <iostream>
using namespace std;

string conversion(const string& str, int x, int y){
	bool neg = str.front()=='-';
	int num = 0;
	string res;
	for(int i = (neg?1:0);i<str.size();i++){
		num *= x;
		num += isdigit(str[i])?str[i]-'0':str[i]-'A'+10; 
	}
	while(num){
		int k = num % y;
		res.push_back(k>=10?'A'+k-10:'0'+k);
		num /= y;
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
	string input = "1590999";
	cout<<conversion(input,10,16);
}