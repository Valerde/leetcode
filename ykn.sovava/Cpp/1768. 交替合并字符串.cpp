#include<bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
	string res;
	int n = min(word1.size(),word2.size());
	for(int i = 0; i<n; i++) {
		res+=word1[i];
		res+=word2[i];
	}
	for(int i = n; i<word1.size(); i++) {
		res+=word1[i];
	}
	for(int i = n; i<word2.size(); i++) {
		res+=word2[i];
	}
	return res;
}

int main() {
	string temp ;
	temp+="qwer";
	cout<<temp;
}
