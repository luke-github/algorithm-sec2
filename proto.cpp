#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> LCA(shared_ptr<BST<int>>& root, shared_ptr<BST<int>>& left, shared_ptr<BST<int>>& right){
	if(!root){
		return nullptr;
	}
	if(root==left || root==right){
		return root;
	}
	shared_ptr<BST<int>> left_res = LCA(root->left,left,right);
	shared_ptr<BST<int>> right_res = LCA(root->right,left,right);
	if(left_res&&right_res){
		return root;
	}else{
		return left_res?left_res:right_res;
	}
}