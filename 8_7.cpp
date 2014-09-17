#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> check_overlap(shared_ptr<ListNode<int>> L, shared_ptr<ListNode<int>> R){
	shared_ptr<ListNode<int>> l1 = has_cycle(L), l2 = has_cycle(R);
	if(!l1&&!l2){
		return no_cycle_overlap(L,R);
	}else if(l1&&l2){
		shared_ptr<ListNode<int>> temp = l2;
		do{
			temp=temp->next;
		}while(temp!=l1&&temp!=l2);
		return temp==l1? l1 : nullptr;
	}else{
		return nullptr;
	}
}