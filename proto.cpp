#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

void online_median(istringstream* sin){
	priority_queue<int,vector<int>,greater<int>> H;
	priority_queue<int,vector<int>,less<int>> L;
	int x;
	while(*sin>>x){
		if(x>H.top()){
			H.emplace(x);
		}else{
			L.emplace(x);
		}

		if(H.size()>L.size()+1){
			L.emplace(H.top());
			H.pop();
		}else if(L.size()>H.size()+1){
			H.emplace(L.top());
			L.pop();
		}

		if(H.size()==L.size()){
			cout<<0.5*(H.top()+L.top());
		}else{
			cout<< (H.size()>L.size()?H.top():L.top());
		}
	}
}