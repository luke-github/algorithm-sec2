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

int getDepth(shared_ptr<BST<int>> node){
	int res = 0;
	while(node){
		res++;
		node = node->parent;
	}
	return res;
}

shared_ptr<BST<int>> LCA(shared_ptr<BST<int>>& node1, shared_ptr<BST<int>>& node2){
	int depth1 = getDepth(node1);
	int depth2 = getDepth(node2);
	if(depth1<depth2){
		swap(node1,node2);
	}
	int diff = abs(depth1 - depth2);
	while(diff--){
		node1 = node1->parent;
	}
	while(node1!=node2){
		node1=node1->parent;
	 	node2=node2->parent;
	}
	return node1;
}