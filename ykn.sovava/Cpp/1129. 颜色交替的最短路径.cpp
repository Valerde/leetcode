#include<bits/stdc++.h>
using namespace std;
//0 表示红色 , 1 表示蓝色
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
	//存储红边
	vector<vector<vector<int>>> next(2,vector<vector<int>(n));
	for(auto&& red: redEdges) {
		next[0][red[0]].push_back(red[1]);
	}

	for(auto&& blue:blueEdges) {
		next[1][blue[0]].push_back(blue[2]);
	}


	vector<vector<int>> dist(2,vector<int>(n,INT_MAX));
	queue<pair<int,int>> q;
	q.push({0,0});
	q.push({0,1});
	dist[0][0] = 0;
	dist[1][0] = 0;

	while(!q.empty()) {
		auto [x,t] = q.front();
		q.pop();
		for(auto y: next[1-t][x]) {
			if(dist[1-t][y] != INT_MAX) {
				continue;
			}
			dist[1-t][y] = dist[t][x] + 1;
			q.push({y, 1-t});
		}
	}
	vector<int> answer(n);
	for(int i = 0; i<n; i++) {
		answer[i] = min(dist[0][i],dist[1][i]);
		if(answer[i] == INT_MAX ) {
			answer[i] = -1;
		}
	}
	return answer;
}

}
