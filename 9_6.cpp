#include <iostream>
#include <memory>
#include <stack>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

void BST_iteration_algorithm(shared_ptr<BST<int>> node){
	stack<shared_ptr<BST<int>>> st;
	shared_ptr<BST<int>> cur = node;
	while(cur || !st.empty()){
		if(cur){
			st.emplace(cur);
			cur=cur->left;
		}else{
			cur = st.top();
			st.pop();
			cout<<cur->data<<" ";
			cur = cur->right;
		}
	}
}

int main(){
	shared_ptr<BST<int>> n1 = make_shared<BST<int>>(BST<int>({1,nullptr,nullptr}));
	shared_ptr<BST<int>> n2 = make_shared<BST<int>>(BST<int>({2,nullptr,nullptr}));
	shared_ptr<BST<int>> n3 = make_shared<BST<int>>(BST<int>({3,nullptr,nullptr}));
	shared_ptr<BST<int>> n4 = make_shared<BST<int>>(BST<int>({4,nullptr,nullptr}));
	shared_ptr<BST<int>> n5 = make_shared<BST<int>>(BST<int>({5,nullptr,nullptr}));
	shared_ptr<BST<int>> n6 = make_shared<BST<int>>(BST<int>({6,nullptr,nullptr}));
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n2->right=n5;
	n3->left=n6;
	BST_iteration_algorithm(n1);
}