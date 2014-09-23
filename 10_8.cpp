#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
	shared_ptr<BST<T>> parent;
};

shared_ptr<BST<int>> kth_node_algorithm(shared_ptr<BST<int>>& root, int k){
	shared_ptr<BST<int>> cur = root;
	while(cur){
		int left_size = cur->left?cur->left->data : 0;
		if(left_size<k-1){
			k-=(left_size+1);
			cur=cur->right;
		}else if(left_size==k-1){
			return cur;
		}else{
			cur=cur->left;
		}
	}
	return nullptr;
}