#include <iostream>
using namespace std;

int random_generator(int a, int b){
	int t = abs(a-b)+1;
	int res;
	do{
		res = 0;
		for(int i=0;(1<<i)<t;i++){
			res += res<<1 | zero_generator();
		}
	}while(res >= t);
	return res + a;
}

