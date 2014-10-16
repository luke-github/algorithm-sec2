#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int data;
	vector<TreeNode*> edges;
};

TreeNode* duplicate_tree(TreeNode* G){
	unordered_map<TreeNode*,TreeNode*> nodemap;
	queue<TreeNode*> q;
	q.emplace(G);
	nodemap.emplace(G,new TreeNode({G->data}));
	while(!q.empty()){
		TreeNode* cur = q.front();
		q.pop();
		for(TreeNode* x : cur->edges){
			if(nodemap.find(x)==nodemap.end()){
				nodemap.emplace(x,new TreeNode({x->data}));
				q.emplace(x);
			}
			nodemap[cur]->edges.emplace_back(nodemap[x]);
		}
	}
	return nodemap[G];
}