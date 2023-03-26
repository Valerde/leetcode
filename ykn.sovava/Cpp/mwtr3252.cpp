#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++) {
		cin>>a[i];
	}
	vector<int> dp(n);
	if(n==1) cout<< a[0];
	else if(n==2) cout<< max(a[0],a[1]);
	else if(n==3) cout<< max(a[0],max(a[1],a[2]));
	else {
		dp[0] = a[0];
		dp[1] = max(a[0],a[1]);
		dp[2] = max(a[0],max(a[1],a[2]));
		for(int i = 3; i<n; i++) {
			int temp = max(dp[i-1],dp[i-2]);
			dp[i] = max(dp[i-3]+a[i],temp);
		}
		cout<<dp[n-1]<<endl;
	}

}
