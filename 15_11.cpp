#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

bool checker_BST_handler(struct shared_ptr<BST<int>> root, int min, int max){
	if(!root){
		return true;
	}else if(root->data < min || root->data > max){
		return false;
	}
	return checker_BST_handler(root->left,min,root->data)&&checker_BST_handler(root->right,root->data,max);
}

bool checker_BST(shared_ptr<BST<int>> root){
	return checker_BST_handler(root,numeric_limits<int>::min(),numeric_limits<int>::max());
}