#include <iostream>
#include <vector>
#include <complex>
using namespace std;

bool is_valid(int i, int j, int val, vector<vector<int>>& vec){
	for(int k=0;k<vec.size();k++){
		if(val==vec[i][k]||val==vec[k][j]){
			return false;
		}
	}
	int num = sqrt(vec.size());
	int row = i/num;
	int col = j/num;
	for(int a=0;a<num;a++){
		for(int b=0;b<num;b++){
			if(val==vec[row*num+a][col*num+b]){
				return false;
			}
		}
	}
	return true;
}

bool sudoku_handler(int i, int j, vector<vector<int>>& vec){
	if(i == vec.size()){
		i=0;
		if(++j == vec.size()){
			return true;
		}
	}
	if(vec[i][j]!=0){
		return sudoku_handler(i+1,j,vec);
	}
	for(int val=1;val<=vec.size();val++){
		if(is_valid(i,j,val,vec)){
			vec[i][j]=val;
			if(sudoku_handler(i+1,j,vec)){
				return true;
			}
		}
	}
	vec[i][j] = 0;
	return false;
}

bool sudoku(vector<vector<int>>& vec){
	if(sudoku_handler(0,0,vec)){
		cout<<"success"<<endl;
	}else{
		cout<<"failed"<<endl;
	}
		for(int i=0;i<9;i++){
		if(i%3==0&&i!=0){
			cout<<"-----------------------"<<endl;
		}
		for(int j=0;j<9;j++){
			cout<<vec[i][j]<<" ";
			if((j+1)%3==0&&j!=0){
				cout<<"| ";
			}
		}
		cout<<endl;
	}
}


int main(){
	vector<vector<int>> input(9,vector<int>(9,0));
	// input[1][2]=8;
	// input[2][3]=3;
	// cout<<input.size();
	sudoku(input);
}