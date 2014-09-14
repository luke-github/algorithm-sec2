#include <iostream>
#include <fstream>
using namespace std;

string tail(string filename, int line_num){
	string res;
	fstream file_ptr(filename);
	file_ptr.seekg(0,ios::end);
	int file_size = file_ptr.tellg();
	int line_count = 0;
	for(int i=0;i<file_size;i++){
		file_ptr.seekg(-1-i,ios::end);
		char c;
		file_ptr.get(c);
		if(c=='\n'){
			line_count++;
			if(line_count==line_num){
				break;
			}
		}
		res.push_back(c);
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	string filename = "text_input";
	cout<<tail(filename,4)<<endl;
}