#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode{
	T data;
	shared_ptr<ListNode<T>> next;
};

bool handle_carry(shared_ptr<ListNode<int>>* node){
	if((*node)->data<10){
		return false;
	}
	(*node)->data -= 10;
	if(!(*node)->next){
		(*node)->next = make_shared<ListNode<int>>(ListNode<int>{0,nullptr});
	}
	((*node)->next->data)++;
	return true;
}

shared_ptr<ListNode<int>> adder_algorithm(shared_ptr<ListNode<int>> L, shared_ptr<ListNode<int>> R){
	shared_ptr<ListNode<int>> res = L;
	while(R){
		L->data += R->data;
		handle_carry(&L);
		if(!L->next){
			L->next = R->next;
		}
		L=L->next;
		R=R->next;
	}
	while(L && handle_carry(&L)){
		L=L->next;
	}
	return res;
}

int main(){
	shared_ptr<ListNode<int>> n1 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> n2 = make_shared<ListNode<int>>(ListNode<int>{2,nullptr});
	shared_ptr<ListNode<int>> n3 = make_shared<ListNode<int>>(ListNode<int>{3,nullptr});
	shared_ptr<ListNode<int>> n4 = make_shared<ListNode<int>>(ListNode<int>{4,nullptr});
	shared_ptr<ListNode<int>> n5 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> n6 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	shared_ptr<ListNode<int>> n7 = make_shared<ListNode<int>>(ListNode<int>{1,nullptr});
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n5->next = n6;
	n6->next = n7;
	auto res = adder_algorithm(n1,n5);
	while(res){
		cout<<res->data<<" ";
		res = res->next;
	}
}