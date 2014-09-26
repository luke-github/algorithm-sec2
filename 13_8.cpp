#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int nearest_algorithm(vector<string>& vec){
	int res = 1<<31 - 1;
	unordered_map<string,int> hash;
	for(int i=0;i<vec.size();i++){
		auto it = hash.find(vec[i]);
		if(it!=hash.end()){
			res = min(res,i - it->second);					
		}
		hash[vec[i]] = i;
	}
	return res;
}