#include <iostream>
#include <memory>
using namespace std;


template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void handler1(shared_ptr<ListNode<int>> &head){
	shared_ptr<ListNode<int>> p = head;
	p = p->next;
	p->data = 10;
}

void handler2(shared_ptr<ListNode<int>>* head){
	*head = (*head)->next;
	(*head)->data = 10;
		*head = (*head)->next;

}

int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	n1 -> next = n2;
	n2 -> next = n3;
	n3 -> next = n4;
	n4 -> next = n5;
	auto p = n1;
	handler1(p);

	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}


	// shared_ptr<ListNode<int>> p = n1;
	// handler2(&p);
	// while(p){
	// 	cout<<p->data<<" ";
	// 	p=p->next;
	// }

}