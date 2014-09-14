#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> reverse_sub(shared_ptr<ListNode<int>> head, int s, int f){
	if(s==f){
		return head;
	}
	int count = 1;
	shared_ptr<ListNode<int>> s_ptr=head, pre_s_ptr=nullptr;
	while(count<s){
		count++;
		pre_s_ptr = s_ptr;
		s_ptr = s_ptr->next;
	}
	if(pre_s_ptr){
		pre_s_ptr->next=nullptr;
	}
	shared_ptr<ListNode<int>> f_ptr=s_ptr, next_f_ptr = f_ptr->next, cur = s_ptr, pre=nullptr;
	while(count<f){
		f_ptr = cur->next;
		next_f_ptr = f_ptr->next;
		cur->next = pre;
		pre = cur;
		cur = f_ptr;
	}
	f_ptr->next = pre;
	s_ptr->next = next_f_ptr;
	if(pre_s_ptr){
		pre_s_ptr->next = f_ptr;
		return head;
	}else{
		return f_ptr;
	}
}

int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>({1,nullptr}));
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>({2,nullptr}));
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>({3,nullptr}));
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>({4,nullptr}));
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>({5,nullptr}));
	shared_ptr<ListNode<int>> n6 = make_shared<ListNode<int>>(ListNode<int>({6,nullptr}));
	shared_ptr<ListNode<int>> n7 = make_shared<ListNode<int>>(ListNode<int>({7,nullptr}));
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=n7;
	n7->next=nullptr;
	auto res = reverse_sub(n1,2,5);
}