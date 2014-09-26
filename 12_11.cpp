#include <iostream>
#include <vector>
#include <random>
using namespace std;

int k_largest_element_handler(int l, int r, int ran, vector<int>* vec){
	int index = l;
	swap((*vec)[ran],(*vec)[r]);
	for(int i=l;i<r;i++){
		if((*vec)[i]>(*vec)[ran]){
			swap((*vec)[i],(*vec)[index++]);
		}
	}
	swap((*vec)[r],(*vec)[index++]);
	return index;
}

int k_largest_element(vector<int> vec,int k){
	int l = 0, r= vec.size()-1;
	while(l<r){
		default_random_engine gen((random_device())());
		uniform_int_distribution<int> dis(l,r);
		int p = k_largest_element_handler(l,r,dis(gen),&vec);
		if(p==k){
			return vec[p];
		}else if(p<k){
			l = p +1;
		}else{
			r = p-1;
		}
	}

}