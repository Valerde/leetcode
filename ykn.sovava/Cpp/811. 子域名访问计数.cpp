#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
vector<string> subdomainVisits(vector<string>& cpdomains) {
	vector<string> res;
	unordered_map<string,int> counts;

	for(auto&& cpdomain:cpdomains) {
		int space = cpdomain.find(' ');
		int count =  atoi(cpdomain.substr(0,space).c_str());
		string domain = cpdomain.substr(space+1);
		//cout<<space<<"|"<<count<<"|"<<domain<<endl;

		counts[domain]+=count;

		for(int i = 0; i<domain.size(); i++) {
			if(domain[i]=='.')
				counts[domain.substr(i+1)]+=count;
		}
	}

	for(auto i = counts.begin(); i != counts.end(); i++) {
		res.push_back(to_string((i->second))+" "+i->first);
	}


	return res;
}


int main() {

	vector<string> cpdomains {"9001 discuss.leetcode.com"};
	vector<string> res = subdomainVisits(cpdomains);
	
	for(auto&& a:res)
		cout<<a<<endl;
}
