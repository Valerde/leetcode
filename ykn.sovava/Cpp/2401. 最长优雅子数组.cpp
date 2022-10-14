#include<bits/stdc++.h>
using namespace std;
//https://leetcode.cn/problems/longest-nice-subarray/solution/bao-li-mei-ju-pythonjavacgo-by-endlessch-z6t6/
int longestNiceSubarray(vector<int>& nums) {
	int ans = 0;
	for(int i = 0; i<nums.size(); i++) {
		int or_ = 0,j=i;
		while(j>=0&&(or_&nums[j])==0)
			or_|=nums[j--];
		ans=max(ans,i-j);
	}
	return ans;
}


int longestNiceSubarray(vector<int>& nums) {
	int ans = 0;
	for(int left = 0,right = 0,or_ = 0; right<nums.size(); right++) {
		
		while((or_&nums[right])==1)
			or_^=nums[left++];
			or_|=nums[right]
		ans=max(ans,right-left+1);
	}
	return ans;
}
