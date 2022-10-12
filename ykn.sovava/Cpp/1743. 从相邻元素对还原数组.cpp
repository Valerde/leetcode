#include<bits/stdc++.h>
using namespace std;

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

	unordered_map mp<int,vector<int>> ;
	for(auto && val:adjacentPairs) {
		mp[val[0]].push_back(val[1]);
		mp[val[1]].push_back(val[0]);
	}
	int n = adjacentPairs.size()+1;
	int e=0;
	for(auto && [key,vec]: mp)
		if(vec.size()==1) {
			e=key;
			break;
		}

	vector<int> res(n,0);
	res[0]=e;
	res[1]=mp[e][0];
	for(int i = 2; i<n; i++) {
		auto& ret = mp[res[i-1]];
		res[i]= res[i-2]==ret[0]?ret[1]:ret[0];
	}

	return res;
}

int main() {
}
