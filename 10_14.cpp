#include <iostream>
#include <memory>
#include <list>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
	shared_ptr<BST<T>> parent;
};

void leaf_list_handler(shared_ptr<BST<int>>& node, list<shared_ptr<BST<int>>>* res){
	if(node){
		if(!node->left && !node->right){
			res->emplace_back(node);
		}else{
			leaf_list_handler(node->left,res);
			leaf_list_handler(node->right,res);
		}
	}
}

list<shared_ptr<BST<int>>> leaf_list(shared_ptr<BST<int>>& root){
	list<shared_ptr<BST<int>>> res;
	leaf_list_handler(root,&res);
	return res;
}