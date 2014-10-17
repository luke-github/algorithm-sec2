#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool find_all_substring_handler(string& str, unordered_map<string,int>& dict, int start, int unitsize, int numofword){
	unordered_map<string,int> cur_dict;
	for(int i=0;i<numofword;i++){
		string cur_word = str.substr(start+i*unitsize,unitsize);
		if(dict.find(cur_word)==dict.end()){
			return false;
		}
		cur_dict[cur_word]++;
		auto it = dict.find(cur_word);
		if(cur_dict[cur_word]>it->second){
			return false;
		}
	}
	return true;
}

vector<int> find_all_substring(vector<string>& L, string str){
	vector<int> res;
	unordered_map<string, int> dict;
	for(string s : L){
		dict[s]++;
	}
	int unitsize = L.front().size();
	int numofword = L.size();
	for(int i=0;i + unitsize*numofword <=str.size();i++){
		if(find_all_substring_handler(str,dict,i,unitsize,numofword)){
			res.emplace_back(i);
		}
	}
	return res;	
}


int main(){
	vector<string> in = {"aa","bb","cc","dd"};
	auto res = find_all_substring(in,"aaccbbdd");
	for(int x: res){
		cout<<x<<" ";
	}
}