#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> remove_kth_element(shared_ptr<ListNode<int>> head, int k){
	shared_ptr<ListNode<int>> index =  head;
	while(k&&index){
		k--;
		index=index->next;
	}
	if(k){
		throw invalid_argument("the length is incorrect");
	}
	shared_ptr<ListNode<int>> pre = nullptr, cur = head;
	while(index){
		pre = cur;
		cur = cur->next;
		index = index->next;
	}
	if(pre){
		pre->next=cur->next;
		return head;
	}else{
		return cur->next;
	}
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
	auto res = remove_kth_element(n1,3);
	while(res){
		cout<<res->data<<" ";
		res=res->next;
	}
}