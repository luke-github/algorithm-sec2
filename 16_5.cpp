#include <iostream>
#include <vector>
#include <complex>
using namespace std;

void powerset(string str){
	for(int i=0;i<(1<<str.size());i++){
		int x = i;
		while(x){
			int index = log2(x & ~(x-1));
			cout<<str[index];
			if(x &= x-1){
				cout<<endl;
			}
		}
	}
}
int main(){
	powerset("abc");
}