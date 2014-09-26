#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void check_anagram(vector<string> dict){
	unordered_map<string,vector<string>> hash;
	for(string str: dict){
		string sort_str(str);
		sort(sort_str.begin(),sort_str.end());
		hash[sort_str].emplace_back(str);
	}
	for(pair<string,vector<string>> x: hash){
		if(x.second.size()>=2){
			for(string s : x.second){
				cout<<s<<endl;
			}
		}
	}
}