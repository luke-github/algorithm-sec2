#include <iostream>
using namespace std;

struct rectangle{
	int x,y,width,height;
};

bool checker(rectangle& r, rectangle& s){
	if(r.x<s.x+s.width && s.x<r.x+r.width && r.y<s.y+s.height && s.y<r.y+r.height){
		return true;
	}
	return false;
}

rectangle insection(rectangle& r, rectangle& s){
	if(checker(r,s)){
		return {max(r.x,s.x),max(r.y,s.y),min(r.x+r.width,s.x+s.width)-max(r.x,s.x),min(r.y+r.height,s.y+s.height)-max(r.y,s.y)};
	}else{
		return {0,0,-1,-1};
	}
}

int main(){
	rectangle r = {1,1,3,3};
	rectangle s = {2,2,1,1};
	auto res = insection(r,s);
	cout<<res.x<<res.y<<res.width<<res.height<<endl;
}