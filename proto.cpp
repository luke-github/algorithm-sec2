#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> pivot_list(shared_ptr<ListNode<int>> head, int k){
	shared_ptr<ListNode<int>> less_head = nullptr, less_tail = nullptr,
								equal_head = nullptr, equal_tail = nullptr,
								large_head = nullptr, large_tail = nullptr,
								cur = head;
	while(cur){
		if(cur->data < k){
			append_list(cur,&less_head,&less_tail);
		}else if(cur->data == k){
			append_list(cur,&equal_head,&equal_tail);
		}else{
			append_list(cur,&large_head,&large_tail);
		}
		cur=cur->next;
	}
	if(less_tail){
		less_tail->next=nullptr;
	}
	// same for equal and large_tail
	if(large_head){
		equal_tail->next = large_head;
	}
	if(equal_head){
		less_tail->next=equal_head;
	}
	return less_head;

}