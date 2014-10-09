#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ClientCredit{
public:
	bool insert(string name, int num){
		if(clientHash_.emplace(name, num - offset_).second){
			reverseHash_[num - offset_].emplace(name);
			return true;
		}else{
			return false;
		}
	}
	bool remove(string name){
		auto it = clientHash_.find(name);
		if(it!=clientHash_.end()){
			reverseHash_[it->second].erase(name);
			clientHash_.erase(name);
			return true;
		}else{
			return false;
		}
	}
	int lookup(string name){
		auto it = clientHash_.find(name);
		if(it != clientHash_.end()){
			return it->second + offset_;
		}
		else{
			return -1;
		}
	}
	string max(){
		auto it = reverseHash_.rbegin();
		if(it==reverseHash_.rend()){
			return "";
		}else{
			return *it->second.begin();
		}
	}
private:
	int offset_ = 0;
	unordered_map<string,int> clientHash_;
	map<int,unordered_set<string>> reverseHash_;
};