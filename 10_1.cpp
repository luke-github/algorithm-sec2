#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

int Max_height_algorithm(shared_ptr<BST<int>> head){
	if(!head){
		return 0;
	}
	return 1+max(Max_height_algorithm(head->left),Max_height_algorithm(head->right));
}


int Min_height_algorithm(shared_ptr<BST<int>> head){
	if(!head){
		return 0;
	}
	return 1+min(Min_height_algorithm(head->left),Min_height_algorithm(head->right));
}

bool check_balance_tree(shared_ptr<BST<int>> head){
	return Max_height_algorithm(head)-Min_height_algorithm(head)<=1;
}