#include<bits/stdc++.h>
using namespace std;
string decodeMessage(string key, string message) {
	map<char,char> key_map;
	for(int i = 0; i<26; i++)key_map['a'+i]='-';
	for(int i = 0 ,j = 0; i <key.size(); i++) {
		if(key[i]>='a'&&key[i]<='z'&&key_map[key[i]]=='-') {

			key_map[key[i]] = 'a' + j++;
		}
	}
	string res = "";
	for(auto&& c:message) {
		if(c>='a'&&c<='z') {
			res+=key_map[c];
		} else {
			res+=c;
		}
	}
	return res;

}
