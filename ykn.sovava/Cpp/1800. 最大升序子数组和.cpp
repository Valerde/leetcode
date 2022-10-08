#include<bits/stdc++.h>
using namespace std;
int maxAscendingSum(vector<int>& nums) {
	int res=0,n= nums.size(),temp=0;

	for(int i = 0; i < n ; i++ ) {
		if(i==0)temp = nums[0];
		if(i>0) {
			if( nums[i]>nums[i-1]) {
				temp+=nums[i];
			} else {
				temp = nums[i];
			}
		}
		res  = max(temp,res);
	}

	return res;

}

int main() {
	vector<int> nums {10,20,30,40,50};

	cout<<maxAscendingSum(nums);

}
