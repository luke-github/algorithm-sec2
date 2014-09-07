#include <iostream>
#include <vector>
using namespace std;

vector<int> next_permutation(vector<int> vec){
	int k = vec.size()-2;
	while(k>=0){
		if(vec[k]>=vec[k+1]){
			k--;
		}else{
			break;
		}
	}
	int l;
	for(int i=k+1;i<vec.size();i++){
		if(vec[i]>vec[k]){
			l = i;
		}else{
			break;
		}
	}
	swap(vec[k],vec[l]);
	reverse(vec.begin()+k+1,vec.end());	
	return vec;
}

int main(){
	vector<int> vec = {1,2,5,4,3,1,1};
	vector<int> res = next_permutation(vec);
	for(int x: res){
		cout<<x<<" ";
	}
}