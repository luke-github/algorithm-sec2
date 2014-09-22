#include <iostream>
#include <memory>
#include <queue>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

void depty_output_algorithm(shared_ptr<BST<int>> head){
	if(!head){
		return;
	}
	queue<shared_ptr<BST<int>>> q;
	q.emplace(head);
	int count = q.size();
	while(!q.empty()){
		shared_ptr<BST<int>> cur = q.front();
		cout<<cur->data<<" ";
		if(cur->left){
			q.emplace(cur->left);
		}
		if(cur->right){
			q.emplace(cur->right);
		}
		q.pop();
		if(--count==0){
			count = q.size();
			cout<<endl;
		}
	}
}