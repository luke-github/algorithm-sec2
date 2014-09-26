#include <iostream>
#include <unordered_set>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> left;
	shared_ptr<ListNode<T>> right;
	shared_ptr<ListNode<T>> parent;
};

shared_ptr<ListNode<int>> LCA(shared_ptr<ListNode<int>> A, shared_ptr<ListNode<int>> B){
	unordered_set<shared_ptr<ListNode<int>>> hash;
	while(A || B){
		if(A){
			if(hash.emplace(A).second==false){
				return A;
			}
			A = A->parent;
		}
		if(B){
			if(hash.emplace(B).second==false){
				return B;
			}
			B = B->parent;
		}
	}
	throw invalid_argument("error");
}