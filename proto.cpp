#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> rotation_lists(shared_ptr<ListNode<int>> head, int k){
	shared_ptr<ListNode<int>> tail = head;
	int count = 1;
	while(tail){
		count++;
		tail = tail->next;
	}
	tail->next = head;
	k = k%count;
	int step = count - k;
	shared_ptr<ListNode<int>> pre = nullptr, cur = head;
	while(step){
		step--;
		pre = cur;
		cur = cur->next;
	}
	pre->next=nullptr;
	return cur;
}