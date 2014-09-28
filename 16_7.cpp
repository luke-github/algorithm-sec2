#include <iostream>
#include <vector>
using namespace std;

void paren_handler(int remind, int left_num, string& cur, vector<string>& res){
	if(!remind){
		res.emplace_back(cur);
		return;
	}
	if(left_num < remind){
		cur.push_back('(');
		paren_handler(remind-1,left_num+1,cur,res);
		cur.pop_back();
	}
	if(left_num>0){
		cur.push_back(')');
		paren_handler(remind-1,left_num-1,cur,res);
		cur.pop_back();
	}
}

void paren(int n){
	string cur;
	vector<string> res;
	paren_handler(n<<1,0,cur,res);
	for(string x: res){
		cout<<x<<endl;
	}
}

int main(){
	paren(3);
}