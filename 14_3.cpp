#include <iostream>
#include <vector>
using namespace std;

void output_algorithm(string str){
	int count = 1;
	sort(str.begin(),str.end());
	for(int i=1;i<str.size();i++){
		if(str[i]==str[i-1]){
			count++;
		}else{
			cout<<count<<" "<<str[i-1]<<endl;
			count = 1;
		}
	}
	cout<<count<<" "<<str.back()<<endl;
}

int main(){
	output_algorithm("acbcede");
}