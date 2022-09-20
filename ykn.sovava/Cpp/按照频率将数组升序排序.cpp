#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
	unordered_map<int,int> m;
	for(auto&& a:nums) {
		m[a]++;
	}

	sort(nums.begin(),nums.end(),[&](const int a,const int b) {
		if(m[a]!=m[b]) {
			return m[a]<m[b];
		}
		return a>b;
	});
	return nums;


}
int main() {
	vector<int> nums {1,1,1,2,2,3};
	auto ret = frequencySort(nums);
	for(auto a:ret) {
		cout<<a<<" ";
	}
}
