#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

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

bool is_parlidrom(shared_ptr<ListNode<int>> head){
	shared_ptr<ListNode<int>> fast = head, slow = head;
	while(fast){
		fast=fast->next;
		if(fast){
			fast=fast->next;
			slow=slow->next;
		}
	}
	shared_ptr<ListNode<int>> reverse_head = reverse_list(slow);
	while(reverse_head&&head){
		if(reverse_head->data != head->data){
			return false;
		}
		reverse_head=reverse_head->next;
		head=head->next;
	}
	return true;
}

int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> n6 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> n7 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	cout<<is_parlidrom(n1);
}