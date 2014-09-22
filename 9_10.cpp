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

void depth_output_algorithm(shared_ptr<BST<int>> head){
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

int main(){
	shared_ptr<BST<int>> n1 = make_shared<BST<int>>(BST<int>{1,nullptr,nullptr});
	shared_ptr<BST<int>> n2 = make_shared<BST<int>>(BST<int>{2,nullptr,nullptr});
	shared_ptr<BST<int>> n3 = make_shared<BST<int>>(BST<int>{3,nullptr,nullptr});
	shared_ptr<BST<int>> n4 = make_shared<BST<int>>(BST<int>{4,nullptr,nullptr});
	shared_ptr<BST<int>> n5 = make_shared<BST<int>>(BST<int>{5,nullptr,nullptr});
	shared_ptr<BST<int>> n6 = make_shared<BST<int>>(BST<int>{6,nullptr,nullptr});
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n2->right=n5;
	n3->left=n6;
	depth_output_algorithm(n1);
}