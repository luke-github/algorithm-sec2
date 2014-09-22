#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

pair<shared_ptr<BST<int>>,int> find_k_unbalance_handler(shared_ptr<BST<int>> node, int k){
	if(!node){
		return {nullptr,0};
	}
	auto left = find_k_unbalance_handler(node->left,k);
	if(left.first){
		return left;
	}
	auto right = find_k_unbalance_handler(node->right,k);
	if(right.first){
		return right;
	}
	int num_nodes = left.second + right.second+1;
	if(abs(left.second - right.second)>k){
		return {node,num_nodes};
	}else{
		return {nullptr,num_nodes};
	}

}

shared_ptr<BST<int>> find_k_unbalance(shared_ptr<BST<int>> head, int k){
	return find_k_unbalance_handler(head,k).first;
}

