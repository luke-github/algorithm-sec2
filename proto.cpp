#include <iostream>
using namespace std;

double power_handler(double x, int y){
	double res = 1.0;
	int power = y;
	if(power < 0){
		power = -y;
		x = 1.0/x;
	}
	while(power){
		if(power&1){
			res *= x;
		}
		x *= x;
		power>>=1;
	}
	return res;
}

int main(){
	cout<<power_handler(2,-10);
}