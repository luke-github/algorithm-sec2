#include <iostream>
#include <complex>
using namespace std;

bool checker(int i){
	int a = floor(sqrt(i));
	if(a*a==i){
		return true;
	}
	return false;
}

int main(){
	cout<<checker(26);
}
