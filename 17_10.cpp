#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

int minimal_difference(vector<int>& vec){
	int sum = accumulate(vec.begin(),vec.end(),0);
	unordered_set<int> res;
	res.emplace(0);
	for(int item : vec){
		for(int j=sum>>1;j>=item;j--){
			if(res.find(j-item)!=res.end()){
				res.emplace(j);
			}
		}
	}
	for(int j=sum>>1;j>=0;j--){
		if(res.find(j)!=res.end()){
			return sum - j - j;
		}
	}
	return sum;
}

int main(){
	vector<int> in = {1,3,4,10};
	cout<<minimal_difference(in);
}