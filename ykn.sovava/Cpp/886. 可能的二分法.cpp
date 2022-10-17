#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>& color,int curnode,int nowcolor,vector<vector<int>>& div) {
	color[curnode] = nowcolor;
	for(auto&& nextnode:div[curnode]) {
		if(color[nextnode] && color[nextnode]==nowcolor) return false;
		if(!color[nextnode] && !dfs(color,nextnode,3^nowcolor,div)) return false;
	}
	return true;
}
bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
	vector<int> color(n+1,0);
	vector<vector<int>> div(n+1);
	for(auto&& val:dislikes) {
		div[val[0]].push_back(val[1]);
		div[val[1]].push_back(val[0]);
	}

	for(int i = 1; i<=n; i++) {
		if(color[i]==0&& !dfs(color,i,1,div))
			return false;
	}
	return true;
}

int main() {
	vector<vector<int>> dislikes {{1,2}};
	possibleBipartition(5,dislikes);
}



