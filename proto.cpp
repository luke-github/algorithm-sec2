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

void BST_stack_algorithm(shared_ptr<BST<int>> node){
	stack<shared_ptr<BST<int>>> st;
	shared_ptr<BST<int>> cur = node;
	while(cur || !st.empty()){
		if(cur){
			st.emplace(cur);
			cur=cur->left;
		}else{
			cur = st.top();
			st.pop();
			cout<<cur->data<<endl;
			cur = cur ->right;
		}
	}
}