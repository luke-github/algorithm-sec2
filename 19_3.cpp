#include <iostream>
#include <vector>
using namespace std;

void fill_surround_handler(int x,int y,vector<vector<char>>& board, vector<vector<bool>>& visit){
	vector<pair<int,int>> q;
	vector<vector<int>> shfiter = {{1,0},{-1,0},{0,1},{0,-1}};
	bool is_surrounded = true;
	visit[x][y] = true;
	q.emplace_back(x,y);
	int index = 0;
	while(index<q.size()){
		auto cur = q[index++];
		if(cur.first==0||cur.first==board.size()-1||cur.second==0||cur.second==board.size()-1){
			is_surrounded = false;
		}else{
			for(vector<int> m : shfiter){
				pair<int,int> next(cur.first+m[0],cur.second+m[1]);
				if(board[next.first][next.second]=='W'&&!visit[next.first][next.second]){
					visit[next.first][next.second]=true;
					q.emplace_back(next);
				}
			}
		}
	}
	if(is_surrounded){
		for(auto n : q){
			board[n.first][n.second]='B';
		}
	}
}

void fill_surround(vector<vector<char>>& board){
	vector<vector<bool>> visit(board.size(),vector<bool>(board.front().size(),false));
	for(int i=1;i<board.size()-1;i++){
		for(int j=1;j<board.front().size()-1;j++){
			if(board[i][j]=='W'&&!visit[i][j]){
				fill_surround_handler(i,j,board,visit);
			}
		}
	}
}