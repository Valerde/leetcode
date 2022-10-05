#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
	int l = 0,r = nums.size(),m = 0;
	while(l<r) {
		m = l+(r-l)/2;
		if(m%2==1) m--;

		if(nums[m]==nums[m+1]) {
			l=m+2;
		} else {
			r = m;
		}
	}
	return nums[l];
}

int main() {

	vector<int> nums1{1,1,2,3,3,4,4,8,8};
	vector<int> nums2{3};
	
	cout<<singleNonDuplicate(nums2);
}
