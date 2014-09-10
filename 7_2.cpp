#include <iostream>
#include <vector>
using namespace std;

string remove_and_replace_algorithm(string s){
	int write_index = 0, counter_a = 0;
	for(char x : s){
		if(x!='b'){
			s[write_index++]=x;
		}
		if(x=='a'){
			counter_a++;
		}
	}
	int cur_index = write_index - 1;
	s.resize(write_index+counter_a);
	write_index = s.size()-1;
	while(cur_index>=0){
		if(s[cur_index]=='a'){
			s[write_index--] = 'd';
			s[write_index--] = 'd';
		}else{
			s[write_index--] = s[cur_index];
		}
		cur_index--;
	}
	return s;
}

int main(){
	cout<<remove_and_replace_algorithm("bbacebba");
}