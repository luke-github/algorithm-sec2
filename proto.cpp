#include <iostream>
#include <complex>
using namespace std;

bool parlidrome_checker(int num){
	if(num<0){
		return false;
	}
	int num_length = floor(log10(num))+1;
	int left_helper = pow(10,num_length-1);
	int temp_num = num;
	for(int i=0;i<num_length/2;i++){
		if(num/left_helper!=temp_num%10){
			return false;
		}
		num %= left_helper;
		left_helper /=10;
		temp_num /=10;
	}
	return true;
}

int main(){
	cout<<parlidrome_checker(123211);
}