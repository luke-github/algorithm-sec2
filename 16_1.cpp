#include <iostream>
#include <vector>
#include <stack>
#include <array>
using namespace std;

void hanoi_hanlder(int n, array<stack<int>,3>& poles, int from, int to, int use){
	if(n>0){
		hanoi_hanlder(n-1,poles,from,use,to);
		poles[to].push(poles[from].top());
		poles[from].pop();
		cout<<"move from "<<from<<" to "<<to<<endl;
		hanoi_hanlder(n-1,poles,use,to,from);
	}
}

void hanoi(int n){
	array<stack<int>,3> poles;
	for(int i=n;i>0;i--){
		poles[0].push(i);
	}
	hanoi_hanlder(n,poles,0,1,2);
}

int main(){
	hanoi(5);
}