#include <iostream>
#include <vector>
using namespace std;

int first_occurance(vector<int> vec, int k){
	int res = -1;
	int l=0,r=vec.size()-1;
	while(l<=r){
		int m = (l+r)>>1;
		if(vec[m]<k){
			l = m+1;
		}else if(vec[m]==k){
			res = m;
			r = m-1;
		}else{
			r=m-1;
		}
	}
	return res;
}


int main(){
	vector<int> in = {1,3,4,5,5,6,7,8};
	cout<<first_occurance(in,5);
}