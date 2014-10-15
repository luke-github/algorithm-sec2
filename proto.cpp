#include <iostream>
#include <vector>
using namespace std;

void change_colcor(vector<vector<bool>>& vec, int x, int y){
	bool color = vec[x][y];
	vec[x][y] = !vec[x][y];
	vector<vector<int>> shifter = {{1,0},{-1,0},{0,1},{0,-1}};
	for(vector<int> m : shifter){
		int nx = x + m[0], ny = y + m[1];
		if(nx>=0&&nx<vec.size()&&ny>=0&&ny<vec.size()&&vec[nx][ny]==color){
			change_colcor(vec,nx,ny);
		}
	}
}