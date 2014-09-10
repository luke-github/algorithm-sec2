#include <iostream>
#include <vector>
using namespace std;

void rotation_array(vector<vector<int>>& vec){
	for(int layer=0;layer<0.5*vec.size();layer++){
		int first = layer;
		int last = vec.size()-1-first;
		for(int i=first;i<last;i++){
			int offset = i - first;
			int temp = vec[first][i];
			vec[first][i] = vec[last - offset][first];
			vec[last - offset][first] = vec[last][last - offset];
			vec[last][last - offset] = vec[i][last];
			vec[i][last] = temp;
		}
	}
}