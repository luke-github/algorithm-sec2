#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
		shared_ptr<BST<T>> parent;

};

shared_ptr<BST<int>> find_larger(shared_ptr<BST<int>>& root, int k){
	shared_ptr<BST<int>> cur = root;
	shared_ptr<BST<int>> res = nullptr;
	while(cur){
		if(cur->data == k){
			res = cur;
			cur = cur->left;
		}else if(cur->data > k){
			res = cur;
			cur = cur->left;
		}else{
			cur = cur->right;
		}
	}
	return res;
}

shared_ptr<BST<int>> find_next(shared_ptr<BST<int>> node){
	shared_ptr<BST<int>> cur = node;
	if(cur->right){
		shared_ptr<BST<int>> left_most = cur->right;
		while(left_most->left){
			left_most = left_most->left;
		}
		return left_most;
	}else{
		shared_ptr<BST<int>> parent = cur->parent;
		while(parent){
			if(parent->left == cur){
				return parent;
			}
			cur = parent;
			parent = parent->parent;
		}
	}
	return nullptr;
}

vector<shared_ptr<BST<int>>> search_range(shared_ptr<BST<int>> root, int s, int e){
	vector<shared_ptr<BST<int>>> res;
	shared_ptr<BST<int>> cur = find_larger(root,s);
	for(;cur->data < e && cur;cur = find_next(cur)){
		res.emplace_back(cur);
	}
	return res;
}