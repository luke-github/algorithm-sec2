#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> rotation_list(shared_ptr<ListNode<int>> head, int k){
	shared_ptr<ListNode<int>> tail = head;
	int count = 1;
	while(tail){
		count++;
		tail=tail->next;
	}
	k %= count;
	int steps = count-k;
	tail->next = head;
	shared_ptr<ListNode<int>> pre = nullptr, cur = head;
	while(steps){
		steps--;
		pre = cur;
		cur = cur->next;
	}
	pre->next=nullptr;
	return cur;
}

int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	shared_ptr<ListNode<int>> n6 = make_shared<ListNode<int>>(ListNode<int>{6,nullptr});
	shared_ptr<ListNode<int>> n7 = make_shared<ListNode<int>>(ListNode<int>{7,nullptr});
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=n7;
	auto res = rotation_list(n1,3);
	while(res){
		cout<<res->data<<" ";
		res=res->next;
	}
}