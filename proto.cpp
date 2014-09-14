#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void merge_sorted_lists_handler2(shared_ptr<ListNode<int>>* head, shared_ptr<ListNode<int>>* tail, shared_ptr<ListNode<int>> node){
	*head ? (*tail)->next = node : *head = node;
	(*tail) = node;
}

void merge_sorted_lists_handler1(shared_ptr<ListNode<int>>* head, shared_ptr<ListNode<int>>* tail, shared_ptr<ListNode<int>>* node){
	merge_sorted_lists_handler2(head,tail,*node);
	*node=(*node)->next;
}

shared_ptr<ListNode<int>> merge_sorted_lists(shared_ptr<ListNode<int>> left, shared_ptr<ListNode<int>> right){
	shared_ptr<ListNode<int>> head = nullptr, tail = nullptr;
	while(left&&right){
		merge_sorted_lists_handler1(&head,&tail,left->data<right->data?&left:&right);
	}
	if(left){
		merge_sorted_lists_handler2(&head,&tail,left);
	}
	if(right){
		merge_sorted_lists_handler2(&head,&tail,right);
	}
	return head;
}


int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	shared_ptr<ListNode<int>> n6 = make_shared<ListNode<int>>(ListNode<int>{6,nullptr});

	n1->next = n3;
	n3->next = n5;
	n2->next = n4;
	n4->next = n6;
	auto res = merge_sorted_lists(n1,n2);
	while(res){
		cout<<res->data<<" ";
		res=res->next;
	}
}