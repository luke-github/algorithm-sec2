#include <iostream>
#include <vector>
using namespace std;

bool check_farest_point(vector<int>& vec){
	int reach = 0;
	for(int i=0;i<vec.size();i++){
		if(i>reach){
			return false;
		}
		reach = max(reach,i+vec[i]);
	}
	return true;
}

int main(){
	vector<int> in = {3,2,0,0,2,0,1};
	vector<int> in2 = {3,3,1,0,2,0,1};
	cout<<check_farest_point(in2);
}

// the complexity if O(n)