#include <iostream>
#include <complex>
using namespace std;

bool checker(int i){
	double e = sqrt(i);
	int m = floor(e);
	if(m*m==i){
		return true;
	}
	return false;
}

int main(){
	cout<<checker(25);
}