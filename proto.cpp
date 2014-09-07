#include <iostream>
#include <vector>
using namespace std;

void remove_deuplicate(vector<int>& vec){
	int res = 0;
	for(int i=1;i<vec.size();i++){
		if(vec[res]!=vec[i]){
			vec[++res]=vec[i];
		}
	}
}

int main(){
	vector<int> vec = {1,2,2,3,4,5,6,7,7,7,7,7,8,9};
	remove_deuplicate(vec);
	for(int x : vec){
		cout<<x<<" ";
	}
}