#include <iostream>
#include <vector>
using namespace std;

struct Interval{
	int start, end;
};

struct Endpoint{
	bool operator < (const Endpoint& e) const{
		return time!=e.time ? time < e.time : ((isStart) && (!isStart));
	}
	int time;
	bool isStart;
};

int max_concurrent_algorithm(vector<Interval> vec){
	int res = 0;
	vector<Endpoint> point_vec;
	for(Interval x : vec){
		point_vec.emplace_back(Endpoint{x.start,true});
		point_vec.emplace_back(Endpoint{x.end,false});
	}
	sort(point_vec.begin(),point_vec.end());
	int count = 0;
	for(Endpoint e : point_vec){
		if(e.isStart){
			res = max(res,++count);
		}else{
			count--;
		}
	}
	return res;
}

