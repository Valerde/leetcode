/*
״̬���壺
dp[i][j][result=0/1]��ʾ��i��j�����ּ�����Ϊresult�ķ�������
״̬ת�ƣ�
ö������ָ�㣬���ݷָ�����������������������������������Ϊ���ҷ�������ˡ�
�ָ��Ϊ '&':
���Ϊ0 ����������� 0 0, 0 1, 1 0
dp[i][j][0] += dp[i][k - 1][0] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][1] * dp[k + 1][j][0];

���Ϊ1 ��һ������� 1 1
dp[i][j][1] += dp[i][k - 1][1] * dp[k + 1][j][1];

�ָ��Ϊ '|':
���Ϊ0 ��һ������� 0 0
dp[i][j][0] += dp[i][k - 1][0] * dp[k + 1][j][0];

���Ϊ1 ����������� 0 1, 1 0, 1 1
dp[i][j][1] += dp[i][k - 1][0] * dp[k + 1][j][1] + dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][1] * dp[k + 1][j][1];

�ָ��Ϊ '^':
���Ϊ0 ����������� 0 0, 1 1
dp[i][j][0] += dp[i][k - 1][0] * dp[k + 1][j][0] + dp[i][k - 1][1] * dp[k + 1][j][1];

���Ϊ1 ����������� 0 1, 1 0
dp[i][j][1] += dp[i][k - 1][1] * dp[k + 1][j][0] + dp[i][k - 1][0] * dp[k + 1][j][1];

3��base case��
����λ��ʼ��Ϊ1����dp[i][i][0/1] = 1;


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

