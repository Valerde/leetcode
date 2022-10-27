#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
vector<int> dirs {-1,0,1,0,-1};





int shortestBridge(vector<vector<int>>& grid) {
	int n = grid.size();
	int m= grid[0].size();
	queue<pair<int,int>> q;
	vector<int> dirs {-1,0,1,0,-1};


	function<void(int, int)> dfs = [&](int i, int j) {

		grid[i][j] = 2;
		for(int k = 0; k<4; k++) {
			int x = i+dirs[k];
			int y = j+dirs[k+1];
			bool flag=true;
			if(x>=0&&x<n&&y>=0&&y<m) {
				if(grid[x][y] ==0&&flag) {
					q.emplace(i,j);
					flag = false;
				} else	if(grid[x][y]==1) {
					dfs(x,y);
				}

			}
		}
	};

	//Á½´ÎBFS
	int temp = 1;
	for(int i = 0; i<n&&temp==1; i++) {
		for(int j = 0; j<m; j++) {
			if(grid[i][j] == 1) {
				dfs(i,j);
				temp = 0;
				break;

			}
		}
	}


	int res = 0;
	while(true) {

		for(int h = q.size(); h>0; h--) {
			auto a = q.front();
			q.pop();
			int i = a.first;
			int j = a.second;
			for(int k=0; k<4; k++) {
				int x = i+dirs[k];
				int y = j+dirs[k+1];
				if(x>=0&&x<n&&y>=0&&y<m) {
					if(grid[x][y] == 0) {
						q.emplace(x,y);
						grid[x][y] = 2;
					} else if (grid[x][y] == 1) {
						return res;
					}
				}
			}
		}
		res++;
	}
}


int main() {

	vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};

	cout<<shortestBridge(grid);
}
