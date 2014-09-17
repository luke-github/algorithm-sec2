#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> even_odd_merge(shared_ptr<ListNode<int>> head){
	shared_ptr<ListNode<int>> even_index = head, odd_index = head ? head->next : nullptr, odd_first = odd_index, pre_even = nullptr;
	while(even_index&&odd_index){
		even_index->next = odd_index->next;
		pre_even = even_index;
		even_index = even_index->next;
		if(even_index){
			odd_index->next = even_index->next;
			odd_index = odd_index->next;
		}
	}
	if(even_index){
		pre_even = even_index;
	}
	if(pre_even){
		pre_even->next = odd_first;
	}
	return head;
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
	auto res = even_odd_merge(n1);
	while(res){
		cout<<res->data<<" ";
		res=res->next;
	}
}