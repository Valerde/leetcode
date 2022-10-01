#include<bits/stdc++.h>
using namespace std;
/*
��Ҫ����һ����󣬵��ʿ���ѧ���Ѿ�̽������������е���Դ�ֲ������ô�СΪ?m * n ������ grid �����˱�ע��ÿ����Ԫ���е������ͱ�ʾ��һ��Ԫ���еĻƽ�����������õ�Ԫ���ǿյģ���ô���� 0��

Ϊ��ʹ������󻯣�����Ҫ�����¹��������ɻƽ�

ÿ���󹤽���һ����Ԫ���ͻ��ռ��õ�Ԫ���е����лƽ�
��ÿ�ο��Դӵ�ǰλ�������������ĸ������ߡ�
ÿ����Ԫ��ֻ�ܱ����ɣ����룩һ�Ρ�
���ÿ��ɣ����룩�ƽ���ĿΪ 0 �ĵ�Ԫ��
�󹤿��Դ������� ����һ�� �лƽ�ĵ�Ԫ�����������ֹͣ��

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

//���е���� 
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
				if(count>2)///////��Ϊ��ֻ�ܵ����ƶ� , ���Դ����ı��ƿ϶�����õ���ý��,�ӱ�·ͻ��һ���ܵõ����Ž�
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




