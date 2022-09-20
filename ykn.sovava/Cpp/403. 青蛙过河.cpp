#include<bits/stdc++.h>

using namespace std;

/*
��̬�滮
idxΪ��ʱ �������ڵط��� ����,k Ϊ��k����ʯͷ��ȥ
���dp[len-1][k]=true,��ʱ����Ϊk
 dp[i][k]=dp[i-1][k-1]
 dp[i] = dp[i-1][k]
 dp[i][k] = dp[i-1][k+1]

 ����һ��Ϊtrue��ʾ����ת��
  ��ʼ��dp[1][1] = true
  ��ʾλ��1������һ������

  ����:
  ����dp[n-1][j],1<j<n
*/
bool canCross1(vector<int>& stones) {
	int n = stones.size();
	vector<vector<bool>> dp(n,vector<bool>(n,false));
	dp[1][1] = true;
	for(int i = 2; i<n; i++) {
		for(int j = 1; j<i; j++) {
			int k = stones[i]-stones[j];
			if(k<=j+1) {
				dp[i][k] = dp[j][k-1]||dp[j][k]||dp[j][k+1];
			}
		}
	}
	for(int i = 1; i<n; i++) {
		if(dp[n-1][i])
			return true;
	}
	return false;
}

vector<unordered_map<int,int>> rec;
bool dfs(vector<int>& stones,int i,int lastDis) {
	if(i==stones.size()-1) return true;

	if(rec[i].count(lastDis))return rec[i][lastDis];

	for(int curDis = lastDis-1; curDis<lastDis+2; curDis++) {
		if(curDis>0) {
			int j = lower_bound(stones.begin(),stones.end(),curDis+stones[i])-stones.begin();
			if(j!=stones.size()&&stones[j] == curDis + stones[i] &&dfs(stones,j,curDis)) {
				return rec[i][lastDis] =true;
			}
		}
	}
	return rec[i][lastDis] = false;
}

bool canCross(vector<int>& stones) {
	int n = stones.size();
	rec.resize(n);
	return dfs(stones, 0, 0);
}

int main() {
	vector<int> stones {0,1,3,5,6,8,12,17};
	bool flag = canCross(stones);
	cout<<flag;
}
