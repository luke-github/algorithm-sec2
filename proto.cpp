#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int roman_to_int(const string& str){
	unordered_map<char,int> T = {{'X',1},
								{'V',5},
								{'X',10}};
	int res = T[str.back()];
	for(int i = str.size()-2;i>=0;i--){
		if(T[str[i]]<T[str[i+1]]){
			res -= T[str[i]];
		}else{
			res += T[str[i]];
		}
	}
	return res;
}