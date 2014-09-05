#include <iostream>
#include <vector>
using namespace std;

void remove_element(vector<int>* vec, int k){
	int index = 0;
	for(int i=0;i<vec->size();i++){
		if((*vec)[i]!=k){
			(*vec)[index++]=(*vec)[i];
		}
	}
}

int main(){
	vector<int> in = {1,2,3,4,4,4,5,4,6,7};
	remove_element(&in,4);
	for(int x: in){
		cout<<x<<" ";
	}
}