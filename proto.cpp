#include <iostream>
#include <vector>
using namespace std;

bool is_valid(const string& str){
	if((str.front()=='0'&&str.size()>1)||str.size()>3){
		return false;
	}
	int val = stoi(str);
	return val<=255&&val>=0;
}

vector<string> check_ipaddress(const string& str){
	vector<string> res;
	for(int i=1;i<4&&i<str.size();i++){
		string first = str.substr(0,i);
		if(is_valid(first)){
			for(int j=1;j<4&&i+j<str.size();j++){
				string second = str.substr(i,j);
				if(is_valid(second)){
					for(int k=1;k<4&&i+j+k<str.size();k++){
						string thrid = str.substr(i+j,k);
						string fouth = str.substr(i+j+k);
						if(is_valid(thrid)&&is_valid(fouth)){
							res.emplace_back(first+"."+second+"."+thrid+"."+fouth);
						}
					}
				}
			}
		}
	}
	return res;
}

int main(){
	string in = "192168010";
	auto res = check_ipaddress(in);
	for(string x : res){
		cout<<x<<endl;
	}
}