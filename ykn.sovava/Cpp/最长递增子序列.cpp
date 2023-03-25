
#include<bits/stdc++.h>
using namespace std;
 
int lengthOfLIS(vector<int>& nums) {
	vector<int> an(0);
	an.push_back(nums[0]);
	for(int i = 1; i<nums.size(); i++) {
		int len = an.size();
		if(nums[i]>an[len-1]) {
			an.push_back(nums[i]);
		} else {
			auto it = lower_bound(an.begin(),an.end(),nums[i]);
			*it = nums[i];
		}
	}
	return an.size();
}

int main() {
	vector<int> an{10,9,2,5,3,7,101,18};
	cout<<lengthOfLIS(an);
}
