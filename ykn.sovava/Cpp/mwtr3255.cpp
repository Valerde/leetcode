#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<int> in(n);
	for(int i = 0; i<n; i++) {
		cin>>in[i];
	}
	int k = 0;
	cin>>k;
	vector<vector<int>> dp(n,vector<int>(k+1,0));
	dp[0][0]=in[0];
	dp[1][0]= max(in[0],in[1]);
	dp[1][1] = in[0]+in[1];

	for(int i = 2; i<n; i++) {
		for(int j=0; j<=k; j++) {
			dp[i][0] = max(dp[i-1][0],dp[i-2][0]+in[i]);
			if(j>0) {
				dp[i][j] = max(dp[i-2][j]+in[i],dp[i-1][j-1]+in[i]);
			}

		}
	}
	int ma = *max_element(dp[n-1].begin(),dp[n-1].end());
	cout<<ma<<endl;
}
