#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<pair<int,int>> sunset_algorithm(istringstream* sin){
	int height;
	int index = 0;
	vector<pair<int,int>> res;
	while(*sin>>height){
		while(!res.empty() && height>res.back().second){
			res.pop_back();
		}
		res.emplace_back(index++,height);
	}
	return res;
}

// complexity is n