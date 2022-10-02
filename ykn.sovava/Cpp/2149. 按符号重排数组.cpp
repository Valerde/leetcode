#include<bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
	int n = nums.size();
	vector<int> res;
	int a=0,b=0;
	for(int i = 0; 2*i<n; i++) {
		while(nums[a]<0) {
			a++;
		}
		res.push_back(nums[a++]);
		while(nums[b]>=0) {
			b++;
		}
		res.push_back(nums[b++]);
	}
	return res;
}
int main() {

}
