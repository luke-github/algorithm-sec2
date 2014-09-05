#include <iostream>
#include <vector>
using namespace std;

int remove_duplicate(vector<int>& vec){
	int i=0,j=1;
	for(;j<vec.size();j++){
		if(vec[i]!=vec[j]){
			vec[++i]=vec[j];
		}
	}
	return i+1;
}

int main(){
	vector<int> in = {1,2,2,3,4,4,5,6,6};
	int res = remove_duplicate(in);
	for(int x: in){
		cout<<x<<" ";
	}
}