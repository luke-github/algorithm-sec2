#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void append_node(shared_ptr<ListNode<int>> node, shared_ptr<ListNode<int>>* head, shared_ptr<ListNode<int>>* tail){
	if(*head){
		(*head)=node;
		(*tail)=node;
	}else{
		(*tail)->next=node;
		(*tail)=(*tail)->next;
	}
}

shared_ptr<ListNode<int>> pivot_list(shared_ptr<ListNode<int>> head, int k){
	shared_ptr<ListNode<int>> less_head = nullptr, less_tail= nullptr, equal_head = nullptr, equal_tail = nullptr, large_head = nullptr, large_tail = nullptr;
	shared_ptr<ListNode<int>> cur = head;
	while(cur){
		if(cur->data < k){
			append_node(cur,&less_head,&less_tail);
		}else if(cur->data == k){
			append_node(cur,&equal_head,&equal_tail);
		}else{
			append_node(cur,&large_head,&large_tail);
		}
		cur=cur->next;
	}
	if(less_tail){
		less_tail->next=nullptr;
	}
	if(equal_tail){
		equal_tail->next=nullptr;
	}
	if(large_tail){
		large_tail->next=nullptr;
	}
	if(large_head){
		equal_tail->next=large_head;
	}
	if(equal_head){
		less_tail->next=equal_head;
	}
	return less_head;
}

int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	shared_ptr<ListNode<int>> n6 = make_shared<ListNode<int>>(ListNode<int>{6,nullptr});
	shared_ptr<ListNode<int>> n7 = make_shared<ListNode<int>>(ListNode<int>{7,nullptr});
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	auto res = pivot_list(n1,3);
}





