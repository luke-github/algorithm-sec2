#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool check_parilidrom(string str){
	unordered_map<char,int> hash;
	for(char c : str){
		hash[c]++;
	}
	int counter = 0;
	for(pair<char,int> x : hash){
		if(x.second&1 && ++counter>1){
			return false;
		}
	}
	return true;
}

int main(){
	cout<<check_parilidrom("aab");
}