#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
	if(nums.size()==0){
		return 0;
	}
	int N = nums.size();
	vector<int> dp(N+1);
	dp[0]=0;
	dp[1]=nums[0];
	for(int i=2;i<=N;i++){
		dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
	}
	return dp[N];
}
int main() {
	vector<int> nums{2,7,9,3,1};
	cout<<rob(nums);
}
