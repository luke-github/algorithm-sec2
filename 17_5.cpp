#include <iostream>
#include <vector>
using namespace std;

int num_ways(vector<vector<int>>& A){
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			A[i][j] += max((i<1?0:A[i-1][j]),(j<1?0:A[i][j-1]));
		}
	}
	return A.back().back();
}

int main(){
	vector<vector<int>> in = { {1,2,3},{1,2,3},{1,2,3} };
	cout<<num_ways(in);
}