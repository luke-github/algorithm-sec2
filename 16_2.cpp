#include <iostream>
#include <vector>
#include <array>
using namespace std;

array<int,8> vec;

bool checker(int index){
	for(int i=0;i<index;i++){
		int diff = abs(vec[index]-vec[i]);
		if(diff==0||diff==index-i){
			return false;
		}
	}
	return true;
}

void eight_queen_hanler(int index){
	if(index==8){
		for(int x: vec){
			cout<<x<<" ";
		}
		cout<<endl;
	}else{
		for(int i=0;i<8;i++){
			vec[index]=i;
			if(checker(index)){
				eight_queen_hanler(index+1);
			}
		}
	}

}
int main(){
	eight_queen_hanler(0);
}