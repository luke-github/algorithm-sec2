#include <iostream>
#include <vector>
using namespace std;

int compare(double a, double b){
	double diff = (a-b)/b;
	return diff < -numeric_limits<double>::epsilon() ? -1 : diff > numeric_limits<double>::epsilon();
}

double real_sqrt(double x){
	double l,r;
	if(compare(x,1.0)<0){
		l = x; r = 1.0;
	}else{
		l=1.0; r = x;
	}
	while(compare(l,r)<0){
		double m = (l+r)*0.5;
		double val = m*m;
		if(compare(val,x)==0){
			return m;
		}else if(compare(val,x)==1){
			r = m;

		}else{
			l = m;
		}
	}
	return l;
}

int main(){
	cout<<real_sqrt(0.9);
}