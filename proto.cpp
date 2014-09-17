#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> reverse_list(shared_ptr<ListNode<int>> head);

bool is_parlidrom(shared_ptr<ListNode<int>> head){
	shared_ptr<ListNode<int>> fast = head, slow = head;
	while(fast){
		fast=fast->next;
		if(fast){
			fast=fast->next;
			slow=slow->next;
		}
	}
	shared_ptr<ListNode<int>> reverse_node = reverse_list(slow);
	while(reverse_node&&head){
		if(reverse_node->data!=head->data){
			return false;
		}else{
			reverse_node=reverse_node->next;
			head=head->next;
		}
	}
	return true;
}

shared_ptr<ListNode<int>> reverse_list(shared_ptr<ListNode<int>> head){
	shared_ptr<ListNode<int>> cur = head, pre = nullptr;
	while(cur){
		shared_ptr<ListNode<int>> temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre;
}