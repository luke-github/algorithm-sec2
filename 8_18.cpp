// if you want to sort a ListNode and use insertion method, the complexity is n sqr
#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> sort_list(shared_ptr<ListNode<int>> L){
	shared_ptr<ListNode<int>> cur = L, head = nullptr;
	while(cur){
		shared_ptr<ListNode<int>> next = cur->next;
		cur->next = nullptr;
		if(head){
			shared_ptr<ListNode<int>> index = L, pre_index = nullptr;
			while(index&& cur->data>=index->data){
				pre_index=index;
				index=index->next;
			}
			cur->next = index;
			if(pre_index){
				pre_index->next = cur;
			}else{
				head = cur;
			}
		}else{
			head = cur;
		}
		cur=next;
	}
	return head; 
}

int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>{9,nullptr});
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>{7,nullptr});
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	shared_ptr<ListNode<int>> n6 = make_shared<ListNode<int>>(ListNode<int>{10,nullptr});
	shared_ptr<ListNode<int>> n7 = make_shared<ListNode<int>>(ListNode<int>{6,nullptr});
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	auto res = sort_list(n1);
	while(res){
		cout<<res->data<<" ";
		res=res->next;
	}
}