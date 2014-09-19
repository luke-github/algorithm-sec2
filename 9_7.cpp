#include <iostream>
#include <memory>
#include <stack>
using namespace std;

template<class T>
struct ListNode{
	T data;
	int order = -1;
	shared_ptr<ListNode<T>> next;
	shared_ptr<ListNode<T>> jump;
};

void search_node_recursive(shared_ptr<ListNode<int>> head, int* order_num){
	if(head && head->order==-1){
		cout<<head->data<<" ";
		head->order = (*order_num)++;
		search_node_recursive(head->jump,order_num);
		search_node_recursive(head->next,order_num);
	}
}

void search_node_iterate(shared_ptr<ListNode<int>> head){
	stack<shared_ptr<ListNode<int>>> st;
	st.emplace(head);
	int order = 0;
	while(!st.empty()){
		shared_ptr<ListNode<int>> cur = st.top();
		st.pop();
		if(cur && cur->order_num==-1){
			cout<<cur->data<<" ";
			cur->order_num = order++;
			st.emplace(cur->next);
			st.emplace(cur->jump);
		}
	}
}