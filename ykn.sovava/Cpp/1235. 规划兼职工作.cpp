#include<bits/stdc++.h>
using namespace std;
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {

	int n = startTime.size();
	vector<vector<int>> job(n);
	for(int i = 0; i< n; i++)
		job[i] = {startTime[i],endTime[i],profit[i]};


	sort(job.begin(),job.end(),[](vector<int> &a,vector<int> &b) {
		return a[1]<b[1];
	});

	/*
	dp[i] 表示前i份工作可以获得的最大薪资
	dp[n] = max(dp[i-1],dp[k]+ profit[i])
	*/

	vector<int> dp(n+1,0);
	for(int i = 1; i<=n; i++) {
		int k = upper_bound(job.begin(),job.end()+i-1,job[i-1][0],[&](int st, const vector<int> &j) -> bool {
			return st < j[1];
		})-job.begin();
		dp[i]=max(dp[i-1],dp[k]+job[i-1][2]);
	}
	return dp[n];
}



}
