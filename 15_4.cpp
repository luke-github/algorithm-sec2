#include <vector>
#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

void k_largest_nodes_handler(shared_ptr<BST<int>> root, int k, vector<shared_ptr<BST<int>>>& res){
	if(root && k<res.size()){
		k_largest_nodes_handler(root->right,k,res);
		if(k < res.size()){
			res.emplace_back(root);
			k_largest_nodes_handler(root->left,k,res);
		}
	}
}

vector<shared_ptr<BST<int>>> k_largest_nodes(shared_ptr<BST<int>> root, int k){
	vector<shared_ptr<BST<int>>> res;
	k_largest_nodes_handler(root,k,res);
	return res;
}