#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int cmp(vector<int> a,vector<int> b) {

	if (a[0]==b[0]) {
		return a[1]>b[1];
	}
	return a[0]<b[0];
}
int main() {

	int t = 0;
	cin>>t;
	for(int tt = 0; tt<t; tt++) {
		int n = 0;
		cin>>n;
		vector<vector<int>> an(n,vector<int>(2,0));
		for(int i = 0; i<2*n; i++) {
			cin>>an[i%n][i/2];
		}
		sort(an.begin(),an.end(),cmp);
		cout<<" is_sorted"<<is_sorted(an.begin(),an.end(),cmp)<<endl;
		vector<int> dp(n,0);
		dp[0]=0;
		for(int i = 1; i<n; i++) {
			int j = i-1;
			for(; j>=0&&an[j][1]>an[i][1]; j--);
			if(j==0&&an[i][1]==an[j][1])dp[i]=0;
//            else if(j==0&&an[i][1]!=an[j][1])
			else if(j>=0&&an[i][1]==an[j][1]) dp[i]=dp[j];
			else if(j>=0)dp[i]=dp[j]+1;
			else dp[i]=0;
		}
		int ma = 0;
		for(int i = 0; i<n; i++) {
			cout<<dp[i]<<endl;
		}
		ma=*max_element(dp.begin(),dp.end());
		cout<<ma;
	}
	// int a, b;
	// while (cin >> a >> b) { // 注意 while 处理多个 case
	//     cout << a + b << endl;
	// }
}
// 64 位输出请用 printf("%lld")
