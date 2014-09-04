#include <iostream>
using namespace std;

struct rectangle{
	int x,y,width,height;
};

bool checker(rectangle& r, rectangle& s){
	if(r.x<s.x+s.width && s.x<r.x+r.width && s.y<r.y+r.height && r.y<s.y+s.height){
		return true;
	}else{
		return false;
	}
}

rectangle intersection_algo(rectangle& r, rectangle& s){
	if(checker(r,s)){
		return {
			max(r.x,s.x),max(r.y,s.y),min(r.x+r.width,s.x+s.width)-max(r.x,s.x),min(r.y+r.height,s.y+s.height)-max(r.y,s.y)
		};
	}else{
		return {0,0,-1,-1};
	}
}