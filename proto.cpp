#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool find_substring_handler(string str,unordered_map<string,int>& dict, int start, int unitsize,int numofword){
	unordered_map<string,int> cur_dict;
	for(int i=0;i<numofword;i++){
		string cur_word = str.substr(start+i*unitsize,unitsize);
		auto it = dict.find(cur_word);
		if(it==dict.end()){
			return false;
		}
		cur_dict[cur_word]++;
		if(cur_dict[cur_word]>dict[cur_word]){
			return false;
		}
	}
	return true;
}

vector<int> find_substring(vector<string>& vec, string str){
	vector<int> res;
	unordered_map<string, int> dict;
	for(string s : vec){
		dict[s]++;
	}
	int unitsize = vec.front().size();
	int numofword = vec.size();
	for(int i=0;i+unitsize*numofword<=str.size();i++){
		if(find_substring_handler(str,dict,i,unitsize,numofword)){
			res.emplace_back(i);
		}
	}
	return res;
}