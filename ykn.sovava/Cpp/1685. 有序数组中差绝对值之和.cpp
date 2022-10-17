#include<bits/stdc++.h>
using namespace std;
/*
����һ�� �ǵݼ�?������������?nums?��

���㽨��������һ����������?result������?nums?������ͬ����result[i]?����?nums[i]?����������������Ԫ�ز�ľ���ֵ֮�͡�

���仰˵��?result[i]?����?sum(|nums[i]-nums[j]|) ������?0 <= j < nums.length ��?j != i?���±�� 0 ��ʼ����


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
