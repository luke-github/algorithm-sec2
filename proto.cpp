#include <iostream>
#include <vector>
using namespace std;

string reverse_word(string s){
	reverse(s.begin(),s.end());
	int start = 0, end = 0;
	while((end = s.find(" ",start))!=string::npos){
		reverse(s.begin()+start,s.begin()+end);
		start = end + 1;
	}
	reverse(s.begin()+start,s.end());
	return s;
}