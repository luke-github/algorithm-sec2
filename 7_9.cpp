#include <iostream>
#include <vector>
using namespace std;

string snake_output(const string& str){
	string res;
	int index = 1;
	while(index<str.size()){
		res += str[index];
		index += 4;
	}
	index = 0;
	while(index<str.size()){
		res += str[index];
		index += 2;
	}
	index = 3;
	while(index<str.size()){
		res += str[index];
		index += 4;
	}
	return res;
}

int main(){
	string in = "1234567890";
	cout<<snake_output(in);
}