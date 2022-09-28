#include<bits/stdc++.h>
using namespace std;
bool CheckPermutation(string s1, string s2) {
	if(s1.size()!=s2.size())return false;
	int ch[26]= {0};
	for(char c:s1) ch[c-'a']++;
	for(char c:s2) if(--ch[c-'a']<0) return false;

	return true;
}

int main() {
	string s1 = "qwre",s2 = "reaw";
	cout<<CheckPermutation(s1,s2);

}
