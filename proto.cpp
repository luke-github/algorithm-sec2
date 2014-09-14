#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string decode(const string& str){
	int count = 0;
	string res;
	for(char c : str){
		if(isdigit(c)){
			count = count*10 + c- '0';
		}else{
			res.append(count,c);
			count = 0;
		}
	}
	return res;
}

string encode(const string& str){
	int count = 1;
	stringstream res;
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
	string in = "aabbbccc";
	cout<<encode(in)<<endl;
	string in2 = "1a2b3c";
	cout<<decode(in2);

}