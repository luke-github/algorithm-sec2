#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

int median_list(shared_ptr<ListNode<int>> rand_ptr){
	shared_ptr<ListNode<int>> cur = rand_ptr, start = rand_ptr;
	int count = 0;
	do{
		count++;
		cur=cur->next;
		if(start->data <= cur->data){
			start=cur;
		}
	}while(cur!=rand_ptr);
	start = start->next;
	for(int i=0;i<(count-1)>>1;i++){
		start =  start->next;
	}
	return count&1 ? start->data : 0.5*(start->data+start->next->data);
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
	n7->next = n1;
	cout<<median_list(n7);
}