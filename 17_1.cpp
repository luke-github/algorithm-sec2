#include <iostream>
#include <vector>
using namespace std;

int find_combination(int k, vector<int> vec){
	vector<int> res(k+1,0);
	res[0]=1;
	for(int i=0;i<=k;i++){
		for(int cur : vec){
			if(i >= cur){
				res[i] += res[i-cur];
			}
		}
	}
	return res[k];
}

int find_combination_without_permutation(int k, vector<int> vec){
	vector<int> res(k+1,0);
	res[0]=1;
	for(int cur : vec){
		for(int i=cur;i<=k;i++){
			res[i] += res[i-cur];
		}
	}
	return res[k];
}


int main(){
	cout<<find_combination(12,{2,3,7})<<endl;
	cout<<find_combination_without_permutation(12,{2,3,7});
}