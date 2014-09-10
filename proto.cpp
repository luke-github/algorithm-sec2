#include <iostream>
#include <vector>
using namespace std;

string remove_and_replace(string s){
	int write_index = 0, counter_a = 0;
	for(char c : s){
		if(c!='b'){
			s[write_index++] = c;
		}
		if(c=='a'){
			counter_a++;
		}
	}
	s.resize(write_index+counter_a);
	int cur_index = write_index - 1;
	write_index = s.size()-1;
	while(cur_index>=0){
		if(s[cur_index]=='a'){
			s[write_index--]='*';
			s[write_index--]='*';
		}else{
			s[write_index--]=s[cur_index];
		}
		cur_index--;
	}
	return s;
}
int main(){
	cout<<remove_and_replace("bbbasdfasdf");
}