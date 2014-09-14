#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct Node{
	int data;
	shared_ptr<Node<T>> next;
};

void merge_sorted_lists_handler2(shared_ptr<Node<int>>* head, shared_ptr<Node<int>>* tail, shared_ptr<Node<int>> Node){
	*head ? (*tail)->next = Node : (*head) = Node;
	(*tail) = Node;
}

void merge_sorted_lists_handler1(shared_ptr<Node<int>>* head, shared_ptr<Node<int>>* tail, shared_ptr<Node<int>>* Node){
	merge_sorted_lists_handler2(head,tail,*Node);
	(*Node) = (*Node)->next;
}

shared_ptr<Node<int>> merge_sorted_lists(shared_ptr<Node<int>> left, shared_ptr<Node<int>> right){
	shared_ptr<Node<int>> res_head = nullptr, tail = nullptr;
	while(left && right){
		merge_sorted_lists_handler1(&res_head, &tail, left->data<right->data?&left:&right);
	}
	if(left){
		merge_sorted_lists_handler2(&res_head,&tail,left);
	}
	if(right){
		merge_sorted_lists_handler2(&res_head,&tail,right);
	}
	return res_head;
}

int main(){
	shared_ptr<Node<int>> n1 = make_shared<Node<int>>(Node<int>{1,nullptr});
	shared_ptr<Node<int>> n2 = make_shared<Node<int>>(Node<int>{2,nullptr});
	shared_ptr<Node<int>> n3 = make_shared<Node<int>>(Node<int>{3,nullptr});
	shared_ptr<Node<int>> n4 = make_shared<Node<int>>(Node<int>{4,nullptr});
	shared_ptr<Node<int>> n5 = make_shared<Node<int>>(Node<int>{5,nullptr});
	shared_ptr<Node<int>> n6 = make_shared<Node<int>>(Node<int>{6,nullptr});
	n1->next = n3;
	n3->next = n5;
	n2->next = n4;
	n4->next = n6;
	auto res = merge_sorted_lists(n1,n2);
	while(res){
		cout<<res->data<<" ";
		res=res->next;
	}

}