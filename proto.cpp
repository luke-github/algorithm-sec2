#include <iostream>
#include <vector>
using namespace std;

int remove_duplicate(vector<int>& vec){
	int index=0;
	for(int i=1;i<vec.size();i++){
		if(vec[index]!=vec[i]){
			vec[++index]=vec[i];
		}
	}
	return index+1;
}