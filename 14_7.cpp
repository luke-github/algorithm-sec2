#include <iostream>
#include <vector>
using namespace std;

struct Interval{
public:
	struct Endpoint{
		bool isClose;
		int val;
	};
	bool operator < (Interval I) const{
		return start.val != I.start.val ? start.val < I.start.val : start.isClose && ! I.start.isClose;
	}

	Endpoint start, end;
};

vector<Interval> merge_algorithm(vector<Interval> vec){
	vector<Interval> res;
	sort(vec.begin(),vec.end());
	Interval cur = vec[0];
	for(int i=1;i<vec.size();i++){
		if(cur.end.val<vec[i].start.val || (cur.end.val==vec[i].start.val && (cur.end.isClose || vec[i].start.isClose))){
			if(vec[i].end.val > cur.end.val || (vec[i].end.val==cur.end.val && (vec[i].end.isClose || cur.end.isClose))){
				cur.end.val = vec[i].end.val;
			}
		}else{
			res.emplace_back(cur);
			cur = vec[i];
		}
	}
	res.emplace_back(cur);
	return res;
}