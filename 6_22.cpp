#include <iostream>
#include <vector>
#include <complex>
using namespace std;

void ratation_algorithm(vector<vector<int>>& vec, int offset){
	if(offset*2+1==vec.size()){
		cout<<vec[offset][offset];
	}
	for(int i=offset;i<vec.size()-offset-1;i++){
		cout<<vec[offset][i];
	}
	for(int i=offset;i<vec.size()-offset-1;i++){
		cout<<vec[i][vec.size()-offset-1];
	}
	for(int i=vec.size()-offset-1;i>offset;i--){
		cout<<vec[vec.size()-offset-1][i];
	}
	for(int i=vec.size()-offset-1;i>offset;i--){
		cout<<vec[i][offset];
	}
}

void print_ratate_matrix(vector<vector<int>>& vec){
	for(int i=0;i<ceil(0.5*vec.size());i++){
		ratation_algorithm(vec,i);
	}
}