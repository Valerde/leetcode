/*
给你一个下标从 0?开始的整数数组?nums?和一个整数?pivot?。请你将?nums?重新排列，使得以下条件均成立：

所有小于?pivot?的元素都出现在所有大于?pivot?的元素?之前?。
所有等于?pivot?的元素都出现在小于和大于 pivot?的元素 中间?。
小于 pivot?的元素之间和大于 pivot?的元素之间的 相对顺序?不发生改变。
更正式的，考虑每一对?pi，pj?，pi?是初始时位置 i?元素的新位置，pj?是初始时位置?j?元素的新位置。对于小于?pivot?的元素，如果?i < j?且?nums[i] < pivot 和?nums[j] < pivot?都成立，那么?pi < pj?也成立。类似的，对于大于?pivot?的元素，如果?i < j 且?nums[i] > pivot 和?nums[j] > pivot?都成立，那么?pi < pj?。
请你返回重新排列 nums?数组后的结果数组。

*/

#include<bits/stdc++.h>
using namespace std;
vector<int> pivotArray(vector<int>& nums, int pivot) {
	int n = nums.size();

	vector<int> res (n,pivot);
	int left = 0,right = n - 1;

	for(int i = 0; i<n; i++) {
		if(nums[i]<pivot) {
			res[left] = nums[i];
			left++;
		} else if(nums[i]>pivot) {
			res[right]=nums[i];
			right--;
		}
	}
	reverse(res.begin()+right+1,res.end());
	return res;
}
int main() {
	vector<int> nums {9,12,5,10,14,3,10};
	vector<int> res = pivotArray(nums,10);
	for(auto&& val:res)
		cout<<val<<" ";
}
