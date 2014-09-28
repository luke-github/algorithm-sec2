#include <iostream>
#include <vector>
using namespace std;

void permutation_handler(int index,vector<int>& in, vector<vector<int>>& res){
	if(index==in.size()){
		res.emplace_back(in);
		return;
	}
	for(int j=index;j<in.size();j++){
		swap(in[index],in[j]);
		permutation_handler(index+1,in,res);
		swap(in[index],in[j]);
	}
}

void permutation(vector<int> in){
	vector<vector<int>> res;
	permutation_handler(0,in,res);
	for(auto x : res){
		for(int y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}

int main(){
	vector<int> in = {1,2,3,4};
	permutation(in);
}