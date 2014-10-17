#include <iostream>
#include <unordered_set>
using namespace std;

bool check_collatz(int n){
	unordered_set<int> table;
	for(int i=2;i<=n;i++){
		unordered_set<int> sequence;
		int testval = i;
		while(testval>=i){
			if(!sequence.emplace(testval).second){
				return false;
			}
			if(testval&1){
				table.emplace(testval);
				if(testval==1){
					break;
				}
				
				testval = testval*3+1;
			}else{
				testval =testval>>1;
			}
		}
		table.erase(i);
	}
	return true;
}

int main(){
	cout<<check_collatz(123123);
}