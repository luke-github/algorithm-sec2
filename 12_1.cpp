#include <iostream>
#include <vector>
using namespace std;

int first_occurance(vector<int> vec, int k){
	int res = -1;
	int l = 0, r = vec.size()-1;
	while(l<=r){
		int mid = (l+r)>>1;
		if(vec[mid]>k){
			r = mid -1;
		}else if(vec[mid]==k){
			res = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return res;
}

int main(){
	vector<int> in = {1,3,4,5,5,6,7,8};
	cout<<first_occurance(in,5);
}