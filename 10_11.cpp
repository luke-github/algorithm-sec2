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

shared_ptr<BST<int>> successor_node(shared_ptr<BST<int>> node){
	if(!node){
		return nullptr;
	}
	if(node->right){
		shared_ptr<BST<int>> cur = node->right;
		while(cur->left){
			cur=cur->left;
		}
		return cur;
	}else{
		shared_ptr<BST<int>> p = node->parent;
		while(p){
			if(p->left==node){
				return p;
			}
			node = p;
			p = p->parent;
		}
	}
	return nullptr;
}

// the complexity is h that is the height of tree