#include<bits/stdc++.h>
using namespace std;
/*
给你一个 非递减?有序整数数组?nums?。

请你建立并返回一个整数数组?result，它跟?nums?长度相同，且result[i]?等于?nums[i]?与数组中所有其他元素差的绝对值之和。

换句话说，?result[i]?等于?sum(|nums[i]-nums[j]|) ，其中?0 <= j < nums.length 且?j != i?（下标从 0 开始）。


*/
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
	int n = nums.size();
	int rightSums = 0,leftSuns = 0;

	for(auto&& val: nums) rightSums+=val;
	vector<int> res(n,0);
	for(int i = 0; i<n; i++) {
		res[i] = rightSums - (n-i)*nums[i]+nums[i]*i-leftSums;
		leftSums+=nums[i];
		rightSums-=nums[i];
	}
	return res;
}
