#include <iostream>
using namespace std;

int power_handler(double x, int y){
	double res = 1.0;
	int power = y>=0? y : -y;
	while(power){
		if(power&1){
			res *= x;
		}
		x *= x;
		power >>=1;
	}
	return res;
}

int main(){
	cout<<power_handler(2,10);
}

// the complexity of this algorithm is O(n). n is the length of input number.
