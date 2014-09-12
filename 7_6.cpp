#include <iostream>
#include <vector>
using namespace std;

string read_and_write_algorithm(string s){
	string res;
	for(int i=0;i<s.size();i++){
		int count = 1;
		while(i+1<s.size() && s[i]==s[i+1]){
			count++;
			i++;
		}
		res += to_string(count)+s[i];
	}
	return res;
}


string read_and_write(int n){
	string s = "1";
	for(int i=1;i<n;i++){
		s = read_and_write_algorithm(s);
	}
	return s;
}

int main(){
	cout<<read_and_write(4);
}