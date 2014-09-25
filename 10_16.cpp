#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
	shared_ptr<BST<T>> next;
};

void next_algo(shared_ptr<BST<int>> root){
	shared_ptr<BST<int>> left_shart = root;
	while(left_shart){
		shared_ptr<BST<int>> parent = left_shart;
		while(parent && parent->left){
			parent->left->next = parent->right;
			if(parent->next){
				parent->right->next = parent->next->left;
			}
			parent = parent->next;
		}
		left_shart = left_shart->left;
	}

}