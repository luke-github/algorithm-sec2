#include <iostream>
using namespace std;

int swap_bits(int x,int i, int j){
	if(((x>>i)&1)!=((x>>j)&1)){
		x ^= 1<<i | 1<<j;
	}
	return x;
}

int main(){
	cout<<swap_bits(1,2,0);
}