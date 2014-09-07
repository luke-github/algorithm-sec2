#include <iostream>
#include <iterator>
#include <vector>
#include <random>
using namespace std;

double random_generator(vector<double>& T, vector<double>& P){
	vector<double> prefix;
	prefix.emplace_back(0);
	partial_sum(P.begin(),P.end(),back_inserter(prefix));
	// writer randomer generator function
	default_random_engine gen((random_device())());
	uniform_real_distribution<double> dis(0.0,1.0);
	auto it = upper_bound(prefix.begin(),prefix.end(),dis(gen));
	return T[distance(prefix.begin(),it)-1];
}