#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int roman_to_integer(string s){
	unordered_map<char,int> T = {{'I',1},
								{'X',5},
								{'V',10}};
	int res = T[s.back()];
	for(int i=s.size()-2;i>=0;i--){
		if(T[s[i]]<T[s[i+1]]){
			res -= T[s[i]];
		}else{
			res += T[s[i]];
		}
	}
	return res;
}

int main(){
	cout<<roman_to_integer("VXIII");
}