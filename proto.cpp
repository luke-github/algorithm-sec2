#include <iostream>
#include <map>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

bool check_cycle(shared_ptr<ListNode<int>> head){
	map<shared_ptr<ListNode<int>>,bool> checker;
	while(head){
		if(checker[head]){
			return true;
		}else{
			checker[head]=true;
			head=head->next;
		}
	}
	return false;
}