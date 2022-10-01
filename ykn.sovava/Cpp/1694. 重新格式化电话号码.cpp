#include<bits/stdc++.h>
using namespace std;

string reformatNumber(string number) {
	string num = "";
	for(int i = 0; i<number.size(); i++) {
		if(number[i]>='0'&&number[i]<='9')
			num+=number[i];
	}

	string res = "";
	if(num.size() == 4) {
		res+=num[0];
		res+=num[1];
		res+="-";
		res+=num[2];
		res+=num[3];
		return res;
	} else if(num.size()<=3) {
		for(int j = 0; j<num.size(); j++) res+=num[j];
		return res;
	}

	int count = 0;
	int i = 0;
	for(; i<num.size(); i++) {

		res+=num[i];
		count++;
		if(count==3) {
			count = 0;
			res+="-";

			if(num.size()-1-i<=4)
				break;
		}
	}
	if(num.size()-1-i==4) {
		res+=num[i+1];
		res+=num[i+2];
		res+="-";
		res+=num[i+3];
		res+=num[i+4];
	} else if(num.size()-1-i == 3) {
		res+=num[i+1];
		res+=num[i+2];
		res+=num[i+3];
	} else if(num.size()-1-i == 2) {
		res+=num[i+1];
		res+=num[i+2];
	}
	return res;
}

int main() {
	string number = "1234";
	string res = reformatNumber(number);
	cout<<res;
}
