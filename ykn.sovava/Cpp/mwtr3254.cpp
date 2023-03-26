#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin>>str;
	int len = str.size();
	vector<string> strs;
	string temp="";
	for(int i = 0; i<len; i++) {
		if(str[i]!=';') {
			temp+=str[i];
		} else {
			strs.push_back(temp);
			temp = "";
		}
	}
	unordered_map<string,string> m;
	for(auto& s: strs) {
		bool flag = false;
		string key="";
		string value="";
		for(int i = 0; i<s.size(); i++) {
			if(s[i]!='='&&!flag) {
				key+=s[i];
			} else if(s[i]=='=') {
				flag=true;
			} else if(flag) {
				value+=s[i];
			}
		}
		m.emplace(key,value);
	}
	string q;
	cin>>q;
	cout<<m[q]<<endl;
}
