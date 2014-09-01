#include <iostream>
using namespace std;

int check_parity(int x){
	int result = 0;
	while(x){
		result ^= 1;
		x &= (x-1);
	}
	return result;
}

int check_parity2(int x){
	int result = 0;
	while(x){
		result ^= (x&1);
		x >>=1;
	}
	return result;
}

int main(){
	cout<<check_parity(3)<<endl;
	cout<<check_parity2(3)<<endl;
}