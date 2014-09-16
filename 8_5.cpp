#include <iostream>
#include <map>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

bool check_loop_algorithm(shared_ptr<ListNode<int>> head){
	map<shared_ptr<ListNode<int>>,bool> checker;
	while(head){
		if(checker[head]){
			return false;
		}else{
			checker[head]=true;
			head=head->next;
		}
	}
	return true;
}

int main(){
	shared_ptr<ListNode<int>> L1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> L2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> L3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> L4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> L5 = make_shared<ListNode<int>>(ListNode<int>{5,nullptr});
	L1->next=L2;
	L2->next=L3;
	L3->next=L4;
	L4->next=L5;
	// L5->next=L1;
	cout<<check_loop_algorithm(L1);
}