#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

bool search_k_in_minBST(shared_ptr<BST<int>> root, int k){
	if(root->data > k){
		return false;
	}
	else if(root->data == k){
		return true;
	}
	else if(root->right && k > root->right->data){
		return search_k_in_minBST(root->right,k);
	}
	return search_k_in_minBST(root->left,k);
}