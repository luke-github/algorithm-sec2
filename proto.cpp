#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

bool handle_carry(shared_ptr<ListNode<int>>* node){
	if((*node)->data<10){
		return false;
	}
	(*node)->data -= 10;
	if(!(*node)->next){
		(*node)->next = make_shared<ListNode<int>>(ListNode<int>({0,nullptr}));
	}
	(*node)->next->data++;
	return true;
}

shared_ptr<ListNode<int>> adder_algorithm(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2){
	shared_ptr<ListNode<int>> res = l1;
	while(l2){
		l1->data += l2->data;
		handle_carry(&l1);
		if(!l1->next){
			l1->next = l2->next;
			return res;
		}
		l1=l1->next;
		l2=l2->next;
	}
	while(l1 && handle_carry(&l1)){
		l1=l1->next;
	}
	return res;
}

