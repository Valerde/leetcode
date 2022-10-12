#include<bits/stdc++.h>
using namespace std;

bool areAlmostEqual(string s1, string s2) {
	int cnt = 0;
	vector<int> n(26,0);
	for(int i = 0; i<s1.size(); i++) {
		n[s1[i]-'a']++;
		n[s2[i]-'a']--;
		if(s1[i]-s2[i]!=0) {
			cnt++;
		}
		if(cnt>2) return false;
	}
	for(int i = 0; i<26; i++) {
		if(n[i]!=0) return false;
	}
	if(cnt==1) return false;
	return true;
}


int main() {
	string s1 = "kelb",s2 = "kelb";

	cout<<areAlmostEqual(s1,s2);
}
