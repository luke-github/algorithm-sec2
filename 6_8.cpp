#include <iostream>
#include <vector>
using namespace std;

int min_capacity_algo(vector<int>& vec){
	int capacity = 0, min_height = (1<<31)-1;
	for(int height : vec){
		capacity = max(capacity,height - min_height);
		min_height = min(height,min_height);
	}
	return capacity;
}