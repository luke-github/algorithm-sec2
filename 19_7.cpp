#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct GraphVertex{
	int d = -1;
	vector<GraphVertex*> edges;
};

bool BSF(GraphVertex* node){
	queue<GraphVertex*> q;
	q.emplace(node);
	while(!q.empty()){
		for(GraphVertex* x : q.front()->edges){
			if(x->d == -1){
				x->d = q.front()->d + 1;
				q.emplace(x);
			}else if(x->d == q.front()->d){
				return false;
			}
		}
		q.pop();
	}
	return true;	
}

bool check_graph(vector<GraphVertex>* G){
	for(GraphVertex node : *G){
		if(node.d == -1){
			if(!BSF(&node)){
				return false;
			}
		}
	}
	return true;
}