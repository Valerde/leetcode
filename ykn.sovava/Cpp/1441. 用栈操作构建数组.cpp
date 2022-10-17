#include<bits/stdc++.h>
using namespace std;
vector<string> buildArray(vector<int>& target, int n) {

	vector<string> res;
	
	for(int i = 0,j = 0; i<target.size(); j++) {
		res.emplace_back("Push");
		if(target[i] == j) {
			i++;
		} else {
			res.emplace_back("Pop");
		}
	}
	return res;
}
