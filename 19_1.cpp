#include <iostream>
#include <vector>
using namespace std;

struct Coordinate{
	bool operator == (Coordinate& that){
		return x == that.x && y == that.y;
	}
	int x,y;
};

bool is_ok(Coordinate& p, vector<vector<int>>& maze){
	if(p.x>=0&&p.x<maze.size()&&p.y>=0&&p.y<maze[p.x].size()&&maze[p.x][p.y]==0){
		return true;
	}
	return false;
}

bool maze_algo_handler(Coordinate s, Coordinate e, vector<vector<int>>& maze, vector<Coordinate>& res){
	if(s==e){
		return true;
	}
	vector<vector<int>> shift = {{0,1},{0,-1},{1,0},{-1,0}};
	for(vector<int> vecShift : shift){
		Coordinate next = {s.x+vecShift[0],s.y+vecShift[1]};
		if(is_ok(next,maze)){
			res.emplace_back(next);
			if(maze_algo_handler(next,e,maze,res)){
				return true;
			}
			res.pop_back();
		}
	}
	return false;
}



vector<Coordinate> maze_algo(vector<vector<int>>& maze, Coordinate start, Coordinate end){
	vector<Coordinate> res;
	maze[start.x][start.y] = 1;
	res.emplace_back(start);
	maze_algo_handler(start,end,maze,res);
	return res;
}
