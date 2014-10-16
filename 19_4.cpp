#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


struct TreeNode{
	int data;
	vector<TreeNode*> edges;
};

TreeNode* duplicate_tree(TreeNode* G){
	if(!G){
		return nullptr;
	}
	unordered_map<TreeNode*,TreeNode*> hash;
	queue<TreeNode*> q;
	q.emplace(G);
	hash.emplace(G,new TreeNode({G->data}));
	while(!q.empty()){
		TreeNode* cur = q.front();
		q.pop();
		for(TreeNode* x : cur->edges){
			if(hash.find(x)!=hash.end()){
				hash.emplace(x,new TreeNode({x->data}));
				q.emplace(x);
			}
			hash[cur]->edges.emplace_back(hash[x]);
		}
	}
	return hash[G];
}
