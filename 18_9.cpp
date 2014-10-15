#include <iostream>
#include <sstream>
using namespace std;

string majorityres(istringstream* sin){
	string res, buf;
	int count = 0;
	while(*sin >> buf){
		if(count == 0){
			res = buf;
			count = 1;
		}else if(res == buf){
			count++;
		}else{
			count --;
		}
	}
	return res;
}

int main(){
	string in = "a a b b a a c";
	stringstream ss(in);
	string res = majorityres(&ss);
}