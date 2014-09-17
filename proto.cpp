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
		if(start->data<=cur->data){
			start = cur;
		}
	}while(cur!=rand_ptr);
	start = start->next;
	for(int i=0;i<(count-1)>>1;i++){
		start=start->next;
	}
	return count&1 ? start->data : 0.5*(start->data+start->next->data);
}