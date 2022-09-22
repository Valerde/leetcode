#include<bits/stdc++.h>
using namespace std;

int numSpecial(vector<vector<int>>& mat) {
	int n = mat.size();
	int m = mat[0].size();
	int flag1[n];
	int flag2[m];
	int count = 0;

	for(int i = 0; i<n; i++) flag1[i]=0;
	for(int i = 0; i<m; i++) flag2[i]=0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			flag1[i]+=mat[i][j];
			flag2[j]+=mat[i][j];
		}
	}
	for(int i = 0; i<n; i++) {
		if(flag1[i]==1) {
			for(int j = 0; j<m; j++) {
				if(flag2[j]==1&&mat[i][j]==1) count++;
			}
		}
	}
	return count;
}
int main() {

	vector<vector<int>> mat {{1,0,0},
		{0,0,1},
		{1,0,0}
	};

	cout<<numSpecial(mat);
}
