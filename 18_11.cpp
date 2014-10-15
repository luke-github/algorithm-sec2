#include <iostream>
#include <vector>
using namespace std;

int max_volumn(vector<int> vec){
	int a = 0, b = vec.size()-1;
	int res = (1<<31);
	while(a<b){
		res = max(res, min(vec[a],vec[b])*abs(b-a));
		if(vec[a]<vec[b]){
			a++;
		}else if(vec[a]>vec[b]){
			b--;
		}else{
			a++;
			b--;
		}
	}
	return res;
}