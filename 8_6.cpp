#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

int len_of_list(shared_ptr<ListNode<int>> head){
	int count = 0;
	while(head){
		count++;
		head=head->next;
	}
	return count;
}

void advance_k(shared_ptr<ListNode<int>>* head, int k){
	while(k){
		k--;
		(*head)=(*head)->next;
	}
}


shared_ptr<ListNode<int>> overlap_lists(shared_ptr<ListNode<int>> L, shared_ptr<ListNode<int>> R){
	int len_l = len_of_list(L);
	int len_r = len_of_list(R);
	advance_k(len_l > len_r ? &L : &R,abs(len_l-len_r));
	while(L&&R&&L!=R){
		L=L->next;
		R=R->next;
	}
	return L;
}

int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	shared_ptr<ListNode<int>> n6 = make_shared<ListNode<int>>(ListNode<int>{6,nullptr});
	shared_ptr<ListNode<int>> n7 = make_shared<ListNode<int>>(ListNode<int>{7,nullptr});
	n1->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n2->next = n3;
	n3->next = n4;
	auto res = overlap_lists(n1,n2);
	cout<<res->data;
}