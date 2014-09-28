#include <iostream>
#include <vector>
using namespace std;

void remove_duplicate(vector<int>& vec){
	sort(vec.begin(),vec.end());
	int res_index = 0;
	for(int i=1;i<vec.size();i++){
		if(vec[i]!=vec[res_index]){
			vec[++res_index]=vec[i];
		}
	}
	vec.resize(res_index+1);
}



int main(){
	vector<int> in = {1,1,2,3,3,4,3,5};
	remove_duplicate(in);
	for(int x : in){
		cout<<x<<" ";
	}
}