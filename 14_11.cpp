#include <iostream>
#include <vector>
using namespace std;

bool check_team_algorithm(vector<int> v1, vector<int> v2){
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0,j=0;i<v1.size(),j<v2.size();i++,j++){
		if(v1[i]<v2[j]){
			return false;
		}
	}
	return true;
}