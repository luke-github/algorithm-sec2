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

shared_ptr<BST<int>> LCA(shared_ptr<BST<int>> root, shared_ptr<BST<int>> node1, shared_ptr<BST<int>> node2){
	while(root->data < node1->data || root->data > node2->data){
		while(root->data < node1->data){
			root = root -> right;
		}
		while(root->data > node2->data){
			root = root->left;
		}
	}
	return root;
}