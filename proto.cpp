#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int calculator_algorithm(string str){
	stringstream ss(str);
	string cur;
	stack<int> st;
	while(getline(ss,cur,',')){
		if(cur == "+" || cur == "-" || cur == "*" || cur == "/"){
			int y = st.top();
			st.pop();
			int x = st.top();
			st.pop();
			switch(cur.front()){
				case '+':
					st.emplace(x+y);
					break;
				// case same code here
			}
		}else{
			st.emplace(stoi(cur));
		}
	}
	return st.top();
}