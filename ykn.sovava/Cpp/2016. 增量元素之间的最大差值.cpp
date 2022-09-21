#include<bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int>& nums) {

	// 对于C++中的输入输出操作,这样可以减少时间 
	static const auto io_sync_off = []() {
		// turn off sync
		std::ios::sync_with_stdio(false);
		// untie in/out streams
		std::cin.tie(nullptr);
		return nullptr;
	}();





	int low = nums[0];
	int m = -1;
	for(int i = 1; i<nums.size(); i++) {
		if(nums[i]>low)  m = max(m,nums[i]-low);
		else low = nums[i];
	}
	return m;
}
int main() {

	vector<int> v {7,1,5,4};
	cout<<maximumDifference(v);
}

