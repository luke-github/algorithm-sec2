#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> eve_odd_merge(shared_ptr<ListNode<int>> head){
	shared_ptr<ListNode<int>> even_index = head, odd_index = head ? head->next : nullptr, pre_even_index = nullptr, first_odd_index = odd_index;
	while(odd_index&&even_index){
		even_index->next = odd_index->next;
		pre_even_index = even_index;
		even_index = even_index->next;
		if(even_index){
			odd_index->next = even_index->next;
			odd_index = odd_index->next;
		}
	}
	if(even_index){
		pre_even_index = even_index;
	}
	if(pre_even_index){
		pre_even_index->next=first_odd_index;
	}
	return head;
}