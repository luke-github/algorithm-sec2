#include <iostream>
#include <vector>
using namespace std;

bool find2_sum(vector<int>& vec, int sum){
	int a = 0, b =vec.size()-1;
	while(a<=b){
		if(vec[a]+vec[b]==sum){
			return true;
		}else if(vec[a]+vec[b]<sum){
			a++;
		}else{
			b--;
		}
	}
	return false;
}

bool find3_sum(vector<int>& vec, int k){
	sort(vec.begin(),vec.end());
	for(int x : vec){
		if(find2_sum(vec,k-x)){
			return true;
		}
	}
	return false;
}

int main(){
	vector<int> in = {1,2,3,4,5,6,7};
	cout<<find3_sum(in,4);
}