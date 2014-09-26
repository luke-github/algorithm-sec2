#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool check_letter(const string& L, const string& M){
	unordered_map<char,int> hash;
	for(char c: L){
		hash[c]++;
	}
	for(char c : M){
		auto it = hash.find(c);
		if(it!=hash.end()){
			hash[c]--;
			if(hash[c]==0){
				hash.erase(it);
				if(hash.empty()){
					return true;
				}
			}
		}
	}
	return hash.empty();
}