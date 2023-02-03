#include<bits/stdc++.h>
using namespace std;
int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
	vector<vector<int>> grid(n,vector<int>(n,1));
	for(auto&& m:mines) grid[m[0]][m[1]] =0;

	vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
	int count = 0, count1 = 0 ,res = 0;
	for(int x = 0; x<n; x++) {
		count = 0;
		count1 = 0;
		for(int y = 0 ; y<n; y++) {
			//вС
			if(grid[x][y]==1) count++;
			else count=0;
			dp[x][y] = min(count,dp[x][y]);

			//ср
			if(grid[x][n-y-1] == 1) count1++;
			else count1 = 0;
			dp[x][n-y-1] = min(count1,dp[x][n-y-1]);
		}
	}
	for(int y = 0; y <n; y++) {
		count = 0;
		count1 = 0;
		for(int x = 0; x<n; x++) {
			//ио
			if(grid[x][y] == 1) count++;
			else count = 0;
			dp[x][y] = min(count,dp[x][y]);

			//об
			if(grid[n-x-1][y] == 1) count1++;
			else count1 = 0;
			dp[n-1-x][y] = min(count1,dp[n-1-x][y]);
		}
	}
	for(int x = 0; x<n; x++)
		for(int y = 0; y<n; y++) {
			res = max(res,dp[x][y]);
		}
	return res;
}
