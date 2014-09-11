#include <iostream>
#include <vector>
using namespace std;

vector<string> keypad = {"0","1","abc","edf","ghi","jkl","mno","pqrs","tuv","wxyz"};

void print_combination_handler(string& num, int index, string* res){
	if(index==num.size()){
		cout<<*res<<endl;
	}else{
		for(char c : keypad[num[index]-'0']){
			(*res)[index] = c;
			print_combination_handler(num,index+1,res);
		}
	}
}

void print_combination(string &num){
	string res(num.size(),0);
	print_combination_handler(num,0,&res);
}

int main(){
	string in = "12345";
	print_combination(in);
}
