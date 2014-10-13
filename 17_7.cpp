#include <iostream>
#include <vector>
using namespace std;

struct Item{
	int weight;
	int value;
};

int knapsack_algo(vector<Item>& vec, int W){
	vector<int> res(W+1,0);
	for(int i=0;i<vec.size();i++){
		for(int j=W;j>=vec[i].weight;j--){
			res[j] = max(res[j],res[j - vec[i].weight]+vec[i].value);
		}
	}
	return res[W];
}

int main(){
	vector<Item> in = {
			{4,3},
						{2,4},
						{1,6},
						{5,7}};
	cout<<knapsack_algo(in,6);
}