#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct Node{
	T data;
	shared_ptr<Node<T>> next;
};

shared_ptr<Node<int>> sort_list(shared_ptr<Node<int>> root){
	shared_ptr<Node<int>> fast = root, slow = root, pre_slow = nullptr;
	while(fast){
		fast = fast->next;
		if(fast){
			pre_slow = slow;
			slow = slow->next;
			fast = fast->next;
		}
	}
	pre_slow->next = nullptr;
	fast = sort_list(root);
	slow = sort_list(slow);
	return merge_list(fast,slow);
}