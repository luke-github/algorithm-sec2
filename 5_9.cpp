#include <iostream>
using namespace std;

int converter(const string& str){
	int res = 0;
	for(char x:str){
		res = res*26 + x - 'A' +1;
	}
	return res;
}

int main(){
	cout<<converter("ASADFASDF");
}