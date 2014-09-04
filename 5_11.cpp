#include <iostream>
#include <complex>
using namespace std;

bool parlidrom_checker(int num){
	if(num<0){
		return false;
	}
	int num_length = floor(log10(num))+1;
	int shift = pow(10,num_length-1);
	int temp_num = num;
	for(int i=0;i<num_length/2;i++){
		if(temp_num%10!=num/shift){
			return false;
		}
		temp_num /= 10;
		num %= shift;
		shift /= 10;
	}
	return true;
}

int main(){
	cout<<parlidrom_checker(12);
}