#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<pair<int,int>> sunset_algorithm(istringstream* sin){
	int height;
	int index=0;
	vector<pair<int,int>> res;
	while(*sin>>height){
		while(!res.empty() && height>=res.back().second){
			res.pop_back();
		}
		res.emplace_back(index++,height);
	}
	return res;
}

int main(){
	string in = "1 3 8 5 9 3 7";
	istringstream input(in);
	auto res = sunset_algorithm(&input);
	for(auto x : res){
		cout<<x.first<<":"<<x.second<<endl;
	}
}
