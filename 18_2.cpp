#include <iostream>
#include <vector>
using namespace std;

int min_waitingtime(vector<int>& vec){
	int res = 0;
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		res += vec[i]*(vec.size()-(i+1));
	}
	return res;
}

int main(){
	vector<int> in = {1,2,3};
	cout<<min_waitingtime(in);
}