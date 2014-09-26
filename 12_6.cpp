#include <iostream>
#include <vector>
using namespace std;

int sqrt_algorithm(int x){
	int l=0,r=x;
	while(l+1<r){
		int m = (l+r)>>1;
		int val = m*m;
		if(val==x){
			return m;
		}else if(val<x){
			l = m;
		}else{
			r = m-1;
		}
	}
	if(r*r<=x){
		return r;
	}
	return l;
}

int main(){
	cout<<sqrt_algorithm(16);
}