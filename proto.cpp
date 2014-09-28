#include <iostream>
#include <vector>
using namespace std;

void permutation_handler(int index, vector<char>& in, vector<vector<char>>& res){
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

void permutation(vector<char> in){
	vector<vector<char>> res;
	permutation_handler(0,in,res);
	for(auto x : res){
		for(char y : x){
			cout<<y;
		}
		cout<<endl;
	}
}

int main(){
	string str = "abc";
	vector<char> input;
	for(char c : str){
		input.emplace_back(c);
	}
	permutation(input);
}