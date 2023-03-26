#include<bits/stdc++.h>
using namespace std;
int main(){
	int w;
	cin>>w;
	int n;
	cin>>n;
	vector<int> in(n+1);
	for(int i = 1;i<=n;i++){
		cin>>in[i];
	}
	vector<int> dp(w+1);
	for(int i = 1;i<=n;i++){
		for(int v=w;v>0;v--){
			if(v>=i){
				dp[v] = max(dp[v-i]+in[i],dp[v]);
			}
		}
	}
	cout<< dp[w];
}
