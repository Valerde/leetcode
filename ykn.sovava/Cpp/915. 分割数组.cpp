#include<bits/stdc++.h>
using namespace std;
int partitionDisjoint(vector<int>& nums) {
	int n = nums.size();
	vector<pair<int,int>> flag(n);
	int lm = INT_MAX,rm = INT_MIN;
	for(int i = 0; i<n; i++) {
		lm = min(lm,nums[i]);
		rm = min(rm , nums[n-i-1]);
		flag[i] = {lm,rm};
	}
	int res = 0;
	for(int i =0; i<n; i++) {
		if(flag[i][0]<flag[i][1])
			res = i;
	}
	return res;
}
