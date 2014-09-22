#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

bool check_symantry_handler(shared_ptr<BST<int>>& L, shared_ptr<BST<int>>& R){
	if(!L&&!R){
		return true;
	}else if(L && R){
		return L->data==R->data && check_symantry_handler(L->left,R->right) && check_symantry_handler(L->right,R->left);
	}else{
		return false;
	}
}

bool check_symantry(shared_ptr<BST<int>> head){
	return !head || check_symantry_handler(head->left,head->right);
}