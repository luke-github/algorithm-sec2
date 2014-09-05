#include <iostream>
#include <vector>
using namespace std;

void dutch_flag(int index_pivot, vector<int>* vec){
	int pivot = (*vec)[index_pivot];
	int small = 0 , mid = 0, large = vec->size()-1;
	while(mid<=large){
		if((*vec)[mid]<pivot){
			swap((*vec)[small++],(*vec)[mid++]);
		}else if((*vec)[mid]==pivot){
			mid++;
		}else{
			swap((*vec)[large--],(*vec)[mid]);
		}
	}
}

int main(){
	vector<int> in = {1,3,9,8,7,5,8};
	dutch_flag(4,&in);
	for(int x : in){
		cout<<x<<" ";
	}
}