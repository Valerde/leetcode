#include<bits/stdc++.h>
using namespace std;
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
	sort(word1.begin(),word1.end());
	sort(word2.begin(),word2.end());
	
	string s1 = "", s2 = "";
	for(auto&& s:word1) s1+=s;
	for(auto&& s:word2) s2+=s;
	return s1==s2;
	
}
