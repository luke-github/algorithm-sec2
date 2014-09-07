#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<int> random_permutation(vector<int> vec){
	default_random_engine gen((random_device())());
	for(int i=0;i<vec.size();i++){
		uniform_int_distribution<int> dis(i,vec.size()-1);
		swap(vec[i],vec[dis(gen)]);
	}
	return vec;
}

int main(){
	vector<int> in = {1,2,3,4,5};
	vector<int> res =  random_permutation(in);
	for(int x : res){
		cout<<x<<" ";
	}
}