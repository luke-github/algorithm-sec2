#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template<class T>
struct BST{
	T data;
	shared_ptr<BST<T>> left;
	shared_ptr<BST<T>> right;
};

shared_ptr<BST<int>> build_BST_through_preorder_handler(vector<int>& vec, int start, int end){
	if(start < end){
		int x = start+1;
		while(x<end && vec[x]<vec[start]){
			x++;
		}
		return make_shared<BST<int>>(BST<int>{vec[start],build_BST_through_preorder_handler(vec,start+1,x),build_BST_through_preorder_handler(vec,x+1,end)});

	}
	return nullptr;
}

shared_ptr<BST<int>> build_BST_through_preorder(vector<int>& vec){
	return build_BST_through_preorder_handler(vec,0,vec.size());
}