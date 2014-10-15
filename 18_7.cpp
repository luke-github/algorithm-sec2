#include <iostream>
#include <vector>
using namespace std;

int site_choosing_algo(vector<int>& G, vector<int>& D){
	pair<int,int> res(0,0);
	int carry = 0;
	for(int i=1;i<G.size();i++){
		carry = carry + G[i] - D[i];
		if(carry < res.second){
			res = {i,carry};
		}
	}
	return res.first;
}