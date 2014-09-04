#include <iostream>
using namespace std;

int reverse_func(int a){
	int res = 0;
	while(a){
		res = res*10 + a%10;
		a /= 10;
	}
	return res;
}

int main(){
	cout<<reverse_func(123456);
}