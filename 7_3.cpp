#include <iostream>
#include <vector>
using namespace std;

bool check_parlidorm(string s){
	int i = 0, j=s.size()-1;
	while(i<j){
		while((!isalnum(s[i])) && i<j){
			++i;
		}
		while((!isalnum(s[j]) && i<j)){
			--j;
		}
		if(s[i]!=s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main(){
	string in = "ab cc b   a1";
	cout<<check_parlidorm(in);
}