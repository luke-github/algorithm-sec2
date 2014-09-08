#include <iostream>
#include <vector>
#include <complex>
#include <deque>
using namespace std;

bool checker_algorithm(vector<vector<int>>& A, int row_start, int row_end, int col_start, int col_end, int num){
	deque<bool> is_exist(num+1,false);
	for(int i=row_start;i<row_end;i++){
		for(int j=col_start;j<col_end;j++){
			if(A[i][j]!=0 && is_exist[A[i][j]]){
				return true;
			}
			is_exist[A[i][j]]=true;
		}
	}
	return false;
}

bool check_sudoku(vector<vector<int>>& A){
	// check row
	for(int i=0;i<A.size();i++){
		if(checker_algorithm(A,i,i+1,0,A.size(),A.size())){
			return false;
		}
	}

	// check col
	for(int i=0;i<A.size();i++){
		if(checker_algorithm(A,0,A.size(),i,i+1,A.size())){
			return false;
		}
	}

	int unit = sqrt(A.size());
	for(int i=0;i<unit;i++){
		for(int j=0;j<unit;j++){
			if(checker_algorithm(A,i*unit,(i+1)*unit,j*unit,(j+1)*unit,A.size())) {
				return false;
			}
		}
	}
	return true;
}