#include <iostream>
#include <vector>
using namespace std;


vector<int> merge_algorithm(vector<int>& A, vector<int>& B){
	int index_a = A.size()-1;
	int index_b = B.size()-1;
	int write_index = index_a+index_b+1;
	A.resize(A.size()+B.size());
	while(index_a>=0 && index_b>=0){
		A[write_index--] = A[index_a] > B[index_b] ? A[index_a--] : B[index_b--];
	}
	while(index_b>=0){
		A[write_index--]=B[index_b--];
	}
	return A;
}

int main(){
	vector<int> vec1 = {1,2,3};
	vector<int> vec2 = {4,5,6};
	auto res = merge_algorithm(vec1,vec2);
	for(int x : res){
		cout<<x<<endl;
	}
}