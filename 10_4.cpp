#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> LCA(shared_ptr<BST<int>>& root, shared_ptr<BST<int>>& l, shared_ptr<BST<int>>& r){
	if(!root){
		return nullptr;
	}
	if(root==l || root==r){
		return root;
	}
	shared_ptr<BST<int>> left_res = LCA(root->left,l,r);
	shared_ptr<BST<int>> right_res = LCA(root->right,l,r);
	if(left_res && right_res){
		return root;
	}else{
		return left_res?left_res:right_res;
	}
}