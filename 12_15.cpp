#include <iostream>
#include <vector>
using namespace std;

pair<int,int> duplic_miss(vector<int> vec){
	int sum, square_sum;
	for(int i=0;i<vec.size();i++){
		sum += i - vec[i];
		square_sum += i*i - vec[i]*vec[i];
	}
	return {(square_sum/sum -sum)/2,(square_sum/sum +sum)/2};
}