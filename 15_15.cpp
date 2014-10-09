#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

bool further_checker(shared_ptr<BST<int>> cur, shared_ptr<BST<int>> target, shared_ptr<BST<int>> M){
	while(cur && cur != M && cur != target){
		cur = cur->data > target->data ? cur->left : cur->right;
	}
	return cur == M;
}

bool check_property(shared_ptr<BST<int>> A, shared_ptr<BST<int>> B, shared_ptr<BST<int>> M){
	shared_ptr<BST<int>> cur_A = A;
	shared_ptr<BST<int>> cur_B = B;
	while(cur_A && cur_A!= B && cur_B && cur_B!= A){
		if(cur_A == M || cur_B == M){
			return true;
		}
		cur_A = cur_A->data > cur_B->data ? cur_A->left : cur_A->right;
		cur_B = cur_B->data > cur_A->data ? cur_B->left : cur_B->right;
	}
	if(cur_A == B || cur_B == A){
		return false;
	}
	return further_checker(cur_A,B,M) || further_checker(cur_B,A,M);
}