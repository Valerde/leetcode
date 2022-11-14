#include<bits/stdc++.h>
using namespace std;
vector<string> getPos(string s) {
	vector<string> v;
	if(s[0] != '0' && a[s.size()-1] == '0') {
		v.push_back(s);
	} else if(s[0] == '0') {
		if(s[s.size()-1] == '0') return v;
		else if(s[s.size()-1] !='0') v.push_back(s.substr(0,1)+"."+s.substr(1));
	} else {
		for(int cut = 1; cut < s.size(); i++) {
			v.push_back(s.substr(0,cut)+"."+s.substr(cut));
		}
	}
	return v;
}
vector<string> ambiguousCoordinates(string s) {
	int n = s.size() -2 ;
	s = s.substr(1,n);
	vector<string> res;
	for(int i = 1; i<n; i++) {
		vector<string> l = getPos(s.substr(0,i));
		if(l.size() == 0) continue;

		vector<string> r = getPos(s.substr(i));
		if(r.size() == 0) continue;
		for(auto&& ll:l) {
			for(auto&& rr:r) {
				res.push_back("(" + ll + ", " + rr + ")");
			}
		}
	}
	return res;
}
