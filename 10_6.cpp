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

int sum_algorithm(shared_ptr<BST<int>>& head, int num){
	if(!head){
		return 0;
	}
	num = (num<<1) + head->data;
	if(!head->left && !head->right){
		return num;
	}
	return sum_algorithm(head->left,num) + sum_algorithm(head->right,num);
}