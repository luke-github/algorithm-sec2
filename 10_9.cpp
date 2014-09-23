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

void iterate_nodes(shared_ptr<BST<int>>& root){
	shared_ptr<BST<int>> pre = nullptr, cur = root, next = nullptr;
	if(!root){
		return;
	}
	while(cur){
		if(!pre || pre->left == cur || pre->right == cur){
			if(cur->left){
				next = cur->left;
			}else{
				cout<<cur->data<<" ";
				next = cur->right? cur->right : cur->parent;
			}
		}else if(cur->left==pre){
			cout<<cur->data<<" ";
			next = cur->right ? cur->right : cur->parent;
		}else{
			next = cur->parent;
		}
		pre = cur;
		cur = next;
	}
}