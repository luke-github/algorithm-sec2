#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> search_k(shared_ptr<BST<int>> root, int k){
	shared_ptr<BST<int>> cur = root;
	shared_ptr<BST<int>> first = nullptr;
	while(cur){
		if(cur->data < k){
			cur = cur->right;
		}else if(cur->data > k){
			cur = cur->left;
		}else{
			first = cur;
			cur = cur->left;
		}
	}
	return first;
}
