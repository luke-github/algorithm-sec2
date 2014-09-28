#include <iostream>
#include <vector>
using namespace std;

struct Interval{
	int start, end;
};

vector<Interval> add_element(vector<Interval> vec, Interval newInterval){
	vector<Interval> res;
	int i=0;
	while(i<vec.size() && newInterval.start > vec[i].end){
		res.emplace_back(vec[i++]);
	}
	int start;
	int end;
	while(i<vec.size() && newInterval.end > vec[i].start){
		start = min(newInterval.start,vec[i].start);
		end = max(newInterval.end,vec[i].end);
		i++;
	}
	res.emplace_back(Interval{start,end});
	res.insert(res.end(),vec.begin()+i,vec.end());
	return res;
}