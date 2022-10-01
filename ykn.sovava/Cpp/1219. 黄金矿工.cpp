#include<bits/stdc++.h>
using namespace std;
/*
你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为?m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。

*/



int _getMaximumGold(vector<vector<int>> grid) {
	int drct[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
	int n = grid.size(),	    m = grid[0].size();
	int res = 0;
	function<void(int,int,int)> dfs = [&](int x,int y,int gold) {
		gold +=grid[x][y];
		res = max(res,gold);

		int rec = grid[x][y];
		grid[x][y] = 0;

		for(int i=0; i<4; i++) {
			if((x+drct[i][0])>=0&&(x+drct[i][0])<n&&(y+drct[i][1])>=0&&(y+drct[i][1])<m&&grid[x+drct[i][0]][y+drct[i][1]]!=0)
				dfs(x+drct[i][0],y+drct[i][1],gold);
		}
		grid[x][y] = rec;
	};


	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			if(grid[i][j]!=0)
				dfs(i,j,0);
		}
	}
	return res;
}

//大佬的题解 
const int x_[4]= {0,0,1,-1};
const int y_[4]= {1,-1,0,0};
int m,n;
int dfs(int i,int j,vector<vector<int>>& grid) {

	if(i<0||i>=m||j<0||j>=n) return 0;
	if(grid[i][j]==0) return 0;
	cout<<i<<" "<<j<<endl;
	int cur=grid[i][j];
	grid[i][j]=0;
	int maxval=0;
	for(int k=0; k<4; k++)
		maxval=max(maxval,dfs(i+x_[k],j+y_[k],grid));
	grid[i][j]=cur;
	return cur+maxval;
}

int getMaximumGold(vector<vector<int>>& grid) {
	int res=0;
	m=(int)grid.size();
	n=(int)grid[0].size();
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j]==0)
				continue;
			else {
				int count=0;
				for(int k=0; k<4; k++)
					if((i+x_[k]>=0&&i+x_[k]<m&&j+y_[k]>=0&&j+y_[k]<n)&&grid[i+x_[k]][j+y_[k]]>0)
						count++;
				if(count>2)///////因为他只能单向移动 , 所以从中心爆破肯定不会得到最好结果,从边路突破一定能得到最优解
					continue;
				res=max(res,dfs(i,j,grid));
				cout<<"------"<<endl;
			}

		}
	}
	return res;
}

int main() {
	vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,15,0}};
	cout<< getMaximumGold(grid);
	return 0;
}




