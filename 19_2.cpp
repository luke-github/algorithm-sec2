#include <iostream>
#include <vector>
using namespace std;

void flip_algo(vector<vector<int>>& vec, int x, int y){
	bool colcor = vec[x][y];
	vec[x][y] = !vec[x][y];
	vector<vector<int>> shifter = {{1,0},{-1,0},{0,-1},{0,1}};
	for(auto m : shifter){
		int nx = x+m[0], ny=y+m[1];
		if(nx>=0&&nx<vec.size()&&ny>=0&&ny<vec.size()&&vec[nx][ny]==colcor){
			flip_algo(vec,nx,ny);
		}
	}
}