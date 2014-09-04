#include <iostream>
using namespace std;

int converter(const string& str){
	int res = 0;
	for(char x : str){
		res = 26*res;
		res += x - 'A' +1;
	}
	return res;
}

int main(){
	cout<<converter("AA");
}