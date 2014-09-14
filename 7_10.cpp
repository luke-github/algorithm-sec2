#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string decode(const string& str){
	string res;
	int count = 0;
	for(char c: str){
		if(isdigit(c)){
			count = count*10 + c - '0';
		}else{
			res.append(count,c);
			count=0; 
		}
	}
	return res;
}

string encode(const string& str){
	stringstream res;
	int count = 1;
	for(int i=1;i<str.size();i++){
		if(str[i]==str[i-1]){
			count++;
		}else{
			res << count << str[i-1];
			count = 1;
		}
	}
	res << count << str.back();
	return res.str();
}

int main(){
	string in = "1a2b3c";
	cout<<encode(decode(in));

}