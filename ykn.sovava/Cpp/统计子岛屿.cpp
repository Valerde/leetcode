#include<bits/stdc++.h>
using namespace std;
// 深度优先搜索 
int n,m;

bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j)
	if(i<||i>=n||j<0||j>=m||grid2[i][j]!=1) return true;
	grid2[i][j]==2; // 标记已到达
	
	bool res = true;
	if( grid1[i][j] == 0) res=false;
	
	res = dfs(grid1,grid2,i-1,j)&&res;
	res = dfs(grid1,drid2,i+1,j)&&res;
	res = dfs (grid1,grid2,i,j-1)&&res;
	res = dfs(grid1,grid2,i,j+1)&&res;
	
	return res;

}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
	n = grid1.size();
	m = grid1[0]size();
	int cnt = 0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			if(grid2[i][j]==1) {
				if(dfs(grid1,grid2,i,j)) cnt++;
			}
		}
	}
	return cnt;

}
// 广度优先搜索 


int main() {

}
