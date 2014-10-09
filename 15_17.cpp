#include <iostream>
#include <set>
#include <unordered_map>
#include <numeric>
#include <fstream>
using namespace std;

int get_value(multiset<int>& vec){
	auto it = vec.cbegin();
	advance(it,3);
	return accumulate(vec.cbegin(),it,0);
}

string search_top_3(ifstream* sin){
	unordered_map<string, multiset<int>> hash;
	string name;
	int score;
	while(*sin >> name >> score){
		hash[name].emplace(score);
	}
	string best_stu("no best stu");
	int max_sum = 1<<31;
	for(auto x : hash){
		if(x.second.size()>3){
			int cur = get_value(x.second);
			if(cur > max_sum){
				max_sum = cur;
				best_stu = x.first;
			}
		}
	}
	return best_stu;
}