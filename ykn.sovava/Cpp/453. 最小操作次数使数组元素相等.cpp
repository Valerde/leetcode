#include<bits/stdc++.h>
using namespace std;
/*
����һ������Ϊ n ���������飬ÿ�β�������ʹ n - 1 ��Ԫ������ 1 ����������������Ԫ����ȵ���С����������
*/

//����: n-1��Ԫ��+1 , �൱���ڸ�Ԫ�� ��һ ������Сֵ

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
