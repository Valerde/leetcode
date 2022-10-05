#include<bits/stdc++.h>
using namespace std;
/*
给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。
*/

//分析: n-1个元素+1 , 相当让于各元素 减一 减到最小值

int minMoves(vector<int>& nums) {

	int ans = 0,n = nums.size();
	int minnum = nums[0];
	for(int  i = 0; i<n; i++) {
		if(minnum>nums[i]) {
			ans+=((i)*(minnum-nums[i]));
			minnum = nums[i];
		} else {
			ans+=(nums[i]-minnum);
		}
	}
	return ans;
}

int main(){
	
	vector<int> nums{4,3,2,1};
	cout<<minMoves(nums);
}
