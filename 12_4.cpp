#include <iostream>
#include <vector>
using namespace std;

int mini_element(vector<int> vec){
	int res;
	int l=0,r=vec.size()-1;
	while(l<r){
		int m = (l+r)>>1;
		if(vec[m]>vec[r]){
			l = m+1;
		}else{
			r = m;
		}
	}
	return l;
}