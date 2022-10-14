/*
状态定义：
dp[i][j][result=0/1]表示第i到j个数字计算结果为result的方案数。
状态转移：
枚举区间分割点，根据分割点的情况讨论左右区间计算结果，方案数增量为左右方案数相乘。
分割点为 '&':
结果为0 有三种情况： 0 0, 0 1, 1 0
dp[i][j][0] += dp[i][k - 1][0] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][1] * dp[k + 1][j][0];

结果为1 有一种情况： 1 1
dp[i][j][1] += dp[i][k - 1][1] * dp[k + 1][j][1];

分割点为 '|':
结果为0 有一种情况： 0 0
dp[i][j][0] += dp[i][k - 1][0] * dp[k + 1][j][0];

结果为1 有三种情况： 0 1, 1 0, 1 1
dp[i][j][1] += dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][1] * dp[k + 1][j][1];

分割点为 '^':
结果为0 有两种情况： 0 0, 1 1
dp[i][j][0] += dp[i][k - 1][0] * dp[k + 1][j][0] + dp[i][k - 1][1] * dp[k + 1][j][1];

结果为1 有两种情况： 0 1, 1 0
dp[i][j][1] += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1];

3、base case：
数字位初始化为1，即dp[i][i][0/1] = 1;


*/


#include<bits/stdc++.h>
using namespace std;

public int countEval(String s, int result) {

	
	if(s.size() == 0) return 0;
	if(s.size() == 1) return (s[0]-'0')==result?1:0;
	int n = s.size();
	vector<vector<vector<int>>> dp(n,vector(n,vector<int>(2,0)));
	for(int i = 0; i<n; i++) {
		if(s[i]=='1'||s[i]=='0') dp[i][i][s[i]-'0']=1;
	}


	for(int len = 2; len<=n; len+=2) {
		for(int i = 0; i<=n-len; i+=2) {
			int j = i+len;
			for(int k = i+1; k<j; k+=2) {
				if(s[k] == '&') {
					//0:  1 0   0 1  0 0
					//1: 1 1
					dp[i][j][0] += dp[i][k-1][1]*dp[k+1][j][0]+dp[i][k-1][0]*dp[k+1][j][1]+dp[i][k-1][0]*dp[k+1][j][0];
					dp[i][j][1] += dp[i][k-1][1]*dp[k+1][j][1];
				} else if(s[k] == '^') {
					//1: 1 0  0 1
					//0: 0 0  1 1
					dp[i][j][0] += dp[i][k-1][0]*dp[k+1][j][0]+dp[i][k-1][1]*dp[k+1][j][1];
					dp[i][j][1] += dp[i][k-1][1]*dp[k+1][j][0]+dp[i][k-1][0]*dp[k+1][j][1];
				} else if(s[k] == '|') {
					//1: 1 1  1 0   0 1
					//0: 0 0
					dp[i][j][1] += dp[i][k-1][1]*dp[k+1][j][1]+dp[i][k-1][0]*dp[k+1][j][1]+dp[i][k-1][1]*dp[k+1][j][0];
					dp[i][j][0] += dp[i][k-1][0]*dp[k+1][j][0];
				}
			}
		}
	}
	
	return dp[0][n-1][result];
}

