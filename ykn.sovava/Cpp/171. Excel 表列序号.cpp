#include<bits/stdc++.h>
using namespace std;
int titleToNumber(string columnTitle) {
	int res = 0;
	for(auto&& c: columnTitle){
		res+=c-'A'+1;
	}
	return res;
}
