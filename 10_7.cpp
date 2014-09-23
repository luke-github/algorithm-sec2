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

bool leaf_path_sum_handler(shared_ptr<BST<int>>& head, int path_sum, int sum){
	if(!head){
		return false;
	}
	path_sum += head->data;
	if(!head->left && !head->right){
		return path_sum == sum;
	}
	return leaf_path_sum_handler(head->left,path_sum,sum) || leaf_path_sum_handler(head->right,path_sum,sum);
}

bool leaf_path_sum(shared_ptr<BST<int>> head, int sum){
	return leaf_path_sum_handler(head, 0, sum);
}