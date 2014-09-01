#include <iostream>
using namespace std;

unsigned add_algo(unsigned x, unsigned y){
	unsigned sum = 0, k=1, temp_x=x,temp_y=y, carryin =0;
	while(temp_x || temp_y){
		unsigned xk=x&k, yk=y&k;
		unsigned carryout = xk&yk || xk&carryin || yk&carryin;
		sum |= xk^yk^carryin;
		carryin = carryout<<1;
		k<<=1;
		temp_x>>=1;
		temp_y>>=1;
	}
	return sum|carryin;
}

unsigned multiply_algo(unsigned x, unsigned y){
	unsigned sum = 0;
	while(x){
		if(x&1){
			sum = add_algo(sum,y);
		}
		x>>=1;
		y<<=1;
	}
	return sum;
}

int main(){
	cout<<multiply_algo(4,7);
}