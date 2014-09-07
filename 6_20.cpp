#include <iostream>
#include <vector>
#include <random>
#include <iterator>
using namespace std;

double random_number_generator(vector<double>& T, vector<double>& P){
	vector<double> prefix;
	prefix.emplace_back(0);
	partial_sum(P.cbegin(),P.cend(),back_inserter(prefix));
	default_random_engine gen((random_device())());
	uniform_real_distribution<double> dis(0.0,1.0);
	auto it = upper_bound(prefix.begin(),prefix.end(),dis(gen));
	return T[distance(prefix.begin(),it) - 1];
}

int main(){
	vector<double> t = {1,2,3,4};
	vector<double> p = {0.1,0.2,0.3,0.4};
	cout<<random_number_generator(t,p);
}