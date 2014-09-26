#include <iostream>
#include <vector>
using namespace std;

int first_larger_than(vector<int> vec, int k){
	int l=0,r=vec.size()-1,m=0,res=-1;
	while(l<r){
		m = (l+r)>>1;
		if(vec[m]>k){
			res = m;
			r = m-1;
		}else{
			l = m+1;
		}
	}
	return res;
}

int main(){
	vector<int> in = {1,2,3,4,4,5,6,7};
	cout<<first_larger_than(in,4);
}