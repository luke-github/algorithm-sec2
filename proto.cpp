#include <iostream>
#include <vector>
using namespace std;

void dutch_flag(int pivot_index, vector<int>* vec){
	int pivot = (*vec)[pivot_index];
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