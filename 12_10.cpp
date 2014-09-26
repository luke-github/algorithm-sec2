#include <iostream>
#include <vector>
using namespace std;

pair<int,int> min_max_algorithm(vector<int> vec){
	pair<int,int> res = minmax(vec[0],vec[1]);
	for(int i=2;i+1<vec.size();i=i+2){
		pair<int,int> cur = minmax(vec[i],vec[i+1]);
		res = {min(res.first,cur.first),max(res.second,cur.second)};
	}
	if(vec.size()&1){
		res = {min(res.first,vec.back()),max(res.second,vec.back())} ;
	}
	return res;
}