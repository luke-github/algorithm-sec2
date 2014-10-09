#include <iostream>
#include <vector>
using namespace std;

bool is_palindrom(string str){
	for(int i=0,j=str.size()-1;i<j;i++,j--){
		if(str[i]!=str[j]){
			return false;
		}
	}
	return true;
}

void all_palindrome_handler(string& s, int begin_index, vector<string>& cur, vector<vector<string>>& res){
	if(begin_index==s.size()){
		res.emplace_back(cur);
		return;
	}
	for(int i = begin_index + 1;i<=s.size();i++){
		string prefix = s.substr(begin_index,i - begin_index);
		if(is_palindrom(prefix)){
			cur.emplace_back(prefix);
			all_palindrome_handler(s,i,cur,res);
			cur.pop_back();
		}
	}
}

vector<vector<string>> all_palindrome(string str){
	vector<string> cur;
	vector<vector<string>> res;
	all_palindrome_handler(str,0,cur,res);
	return res;
}

int main(){
	auto res = all_palindrome("aaa");
	for(auto x : res){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}