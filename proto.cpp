#include <iostream>
using namespace std;

int int_to_string(string num){
	int res = 0;
	for(int i=0;i<num.size();i++){
		res = res*10 + num[i]-'0';
	}
	return res;
}

int main(){
	cout<<int_to_string("123");
}