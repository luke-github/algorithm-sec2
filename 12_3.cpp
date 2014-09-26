#include <iostream>
#include <vector>
using namespace std;

int match_int_algorithm(vector<int> vec){
	int l=0,r=vec.size()-1,m=0;
	while(l<r){
		m = (l+r)>>1;
		int val = vec[m]-m;
		if(val==0){
			return m;
		}else if(val > 0){
			r = m-1;
		}else{
			l = m+1;
		}
	}
}