#include <iostream>
#include <fstream>
using namespace std;

string tail(string& filename, int line_num){
	fstream fileptr(filename);
	fileptr.seekg(0,ios::end);
	int file_size = fileptr.tellg();
	int line_count = 0;
	string output;
	for(int i=0;i<file_size;i++){
		fileptr.seekg(-1-i,ios::end);
		char c;
		fileptr.get(c);
		if(c=='\n'){
			line_count++;
			if(line_count==line_num){
				break;
			}
		}
		output.push_back(c);
	}
	reverse(output.begin(),output.end());
	return output;
}

int main(){
	string filename = "text_input";
	cout<<tail(filename,2)<<endl;
}