#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

void remove_node(shared_ptr<ListNode<int>> v){
	v->data=v->next->data;
	v->next=v->next->next;
}