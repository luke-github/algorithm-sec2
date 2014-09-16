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

shared_ptr<ListNode<int>> reverse_k_list(shared_ptr<ListNode<int>> head, int k){
	shared_ptr<ListNode<int>> pre = head, before_pre = nullptr, post = head, before_post = nullptr;
	bool first_run = true;
	while(pre){
		int i = k;
		while(i){
			i--;
			before_post = post;
			post = post->next;
			if(!post){
				break;
			}
		}
		if(i){
			return head;
		}
		before_post->next=nullptr;
		reverse_list(pre);
		if(before_pre){
			before_pre->next=before_post;
		}
		if(first_run){
			head = before_post;
			first_run=false;
		}
		before_pre = pre;
		pre->next = post;
		pre = post;
		before_post = nullptr;
		

	}
	return head;
}

int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>({1,nullptr}));
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>({2,nullptr}));
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>({3,nullptr}));
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>({4,nullptr}));
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>({5,nullptr}));
	shared_ptr<ListNode<int>> n6 = make_shared<ListNode<int>>(ListNode<int>({6,nullptr}));
	shared_ptr<ListNode<int>> n7 = make_shared<ListNode<int>>(ListNode<int>({7,nullptr}));
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=n7;
	auto res = reverse_k_list(n1,2);
	while(res){
		cout<<res->data<<" ";
		res=res->next;
	}
}