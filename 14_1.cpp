#include <iostream>
#include <vector>
using namespace std;

vector<int> common_ele(vector<int>& A, vector<int>& B){
	vector<int> res;
	int i =0 , j=0;
	while(i<A.size()&&j<B.size()){
		if(A[i]==B[j] && (i==0 || A[i]!=A[i-1])){
			res.emplace_back(A[i]);
			i++;
			j++;
		}else if(A[i]<B[j]){
			i++;
		}else{
			j++;
		}
	}
	return res;
}