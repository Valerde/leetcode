#include<bits/stdc++.h>
using namespace std;

int maxDiff(int num) {

	auto replace = [](string& s,char x,char y) {
		for(int i = 0; i<s.size(); i++) {
			if(s[i] ==x) s[i] = y;
		}
	};

	string maxs = to_string(num);
	string mins = to_string(num);

	for(auto&& val:maxs) {
		if(val!='9') {
			replace(maxs,val,'9');
			break;
		}
	}


	for(int i = 0; i<mins.size(); i++) {
		if(i == 0) {
			if(mins[i]!='1') {
				replace(mins,mins[i],'1');
				break;
			}
		} else {
			if(mins[i]!='0'&&mins[i]!=mins[0]) {
				replace(mins,mins[i],'0');
				break;
			}
		}
	}
	return std::stoi(maxs)-std::stoi(mins);
}

int main() {
	int num = 555;
	cout<<maxDiff(num);
}


