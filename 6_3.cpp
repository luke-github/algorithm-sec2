#include <iostream>
#include <vector>
using namespace std;

class BigInt{
public:
	BigInt(int capacity) : sign_(1), digit_(capacity){}
	
	BigInt(string str) : sign_ = str[0]=='-'? -1 : 1, digit_(str.size()-str[0]=='-'){
		for(int i=str.size()-1, j=0;i>=(str[0]=='-');i--,j++){
			digit_[j] = str[i]-'0';
		}
	}

	BigInt operator * (BigInt n){
		sign_ = n.sign_*sign_;
		BigInt result(digit_.size()+n.digit_.size());
		int i=0,j=0;

		for(i=0;i<n.digit_.size();i++){
			if(n.digit_[i]){
				int carry = 0;
				for(j=0;j<digit_.size()||carry;j++){
					int res = result.digit_[i+j] + j<digit_.size()? n.digit_[i] * digit_[j] : 0 + carry;
					result.digit_[i+j] = res%10;
					carry = res/10;
				}
			}
		}
		if(digit_.size()==1&&digit_.front()==0 || n.digit_.size()==1&&n.digit_.front()==0){
			result.sign_=1;
			result.digit_.resize(1);
		}else{
			result.digit_.resize(i+j-1);
		}
		return result;
	}

private:
	int sign_;
	vector<char> digit_;
};