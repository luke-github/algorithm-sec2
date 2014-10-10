#include <iostream>
#include <vector>
using namespace std;

int min_steps(string A, string B){
	int lenA = A.size();
	int lenB = B.size();
	vector<vector<int>> res(lenA+1,vector<int>(lenB+1,0));
	for(int i=0;i<=lenA;i++){
		res[i][0]=i;
	}
	for(int j=0;j<=lenB;j++){
		res[0][j]=j;
	}
	for(int i=1;i<=lenA;i++){
		for(int j=1;j<=lenB;j++){
			if(A[i-1]==B[j-1]){
				res[i][j]=res[i-1][j-1];
			}else{
				res[i][j] = 1 + min(res[i-1][j-1],min(res[i][j-1],res[i-1][j]));
			}
		}
	}
	return res[lenA][lenB];
}

int main(){
	cout<<min_steps("abc","aec");
}