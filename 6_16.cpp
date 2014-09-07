#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<int> sampling_algorithm(vector<int>& vec, int k){
	default_random_engine gen((random_device())());
	for(int i=0;i<k;i++){
		uniform_int_distribution<int> dis(i,vec.size()-1);
		swap(vec[i],vec[dis(gen)]);
	}
	vec.resize(k);
	return vec;
}

int main(){
	vector<int> in = {1,2,3,4,5,6};
	vector<int> res = sampling_algorithm(in,3);
	for(int x : res){
		cout<<x<<" ";
	}
}