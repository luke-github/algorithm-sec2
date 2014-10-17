#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <fstream>
using namespace std;

pair<string,string> best_affinity(ifstream* sin){
	pair<string,string> res;
	unordered_map<string,set<string>> page_user_map;
	string page, user;
	while(*sin>>page>>user){
		page_user_map[page].emplace(user);
	}
	int max_counter = 1<<31;
	for(auto a = page_user_map.begin();a!=page_user_map.end();a++){
		auto b =a;
		for(advance(b,1);b!=page_user_map.end();b++){
			vector<string> cur_res;
			set_intersection(a->second.begin(),a->second.end(),b->second.begin(),b->second.end(),back_inserter(cur_res));
			if(cur_res.size()>max_counter){
				max_counter = cur_res.size();
				res = {a->first,b->first};
			}
		}

	}
	return res;
}