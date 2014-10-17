#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

pair<string,string> best_affinity(ifstream* sin){
	string page;
	string user;
	unordered_map<string,set<string>> page_user_map;
	while(*sin>>page>>user){
		page_user_map[page].emplace(user);
	}
	pair<string,string> res;
	int max_count = 1<<31;
	for(auto a = page_user_map.begin();a!=page_user_map.end();a++){
		auto b =a;
		for(advance(b,1);b!=page_user_map.end();b++){
			vector<string> cur_res;
			set_intersection(a->second.begin(),a->second.end(),b->second.begin(),b->second.end(),back_inserter(cur_res));
			if(cur_res.size()>max_count){
				max_count = cur_res.size();
				res = {a->first,b->first};
			}
		}
	}
	return res;
}