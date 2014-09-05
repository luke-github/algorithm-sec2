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