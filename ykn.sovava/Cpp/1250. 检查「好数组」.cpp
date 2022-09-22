#include<bits/stdc++.h>
using namespace std;


int gcd(int x, int y) {
	int z = y;
	while(x%y!=0) {
		z = x%y;
		x = y;
		y = z;
	}
	return z;
}
bool isGoodArray(vector<int>& nums) {
	
	
	
	for(int i = 1; i<nums.size(); i++) {
		nums[i]=gcd(nums[i-1],nums[i]);
		if(nums[i]==1) return true;
	}

	if(nums[nums.size()-1]==1)
		return true;
	return false;

}
int main() {
	vector<int> nums {29,6,10};
	
	cout<<isGoodArray(nums);
	
}

