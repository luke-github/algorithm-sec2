#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ClientCredit{
public:
	void insert(string name, int num){
		if(clientHash_.emplace(name,num - offset_).second){
			reverseHash_[num - offset_].emplace(name);
		}
	}
	void remove(string name){
		auto it = clientHash_.find(name);
		if(it!=clientHash_.cend()){
			reverseHash_[it->second].erase(name);
			clientHash_.erase(it);
		}
	}
	int lookup(string name){
		auto it = clientHash_.find(name);
		if(it!=clientHash_.cend()){
			return it->second + offset_;
		}else{
			return -1;
		}
	}
	string max(){
		auto it = reverseHash_.rbegin();
		if(it == reverseHash_.rend()){
			return *it->second.cbegin();
		}else{
			return "";
		}
	}
private:
	int offset_ = 0;
	unordered_map<string,int> clientHash_;
	map<int,unordered_set<string>> reverseHash_;
};