#include<bits/stdc++.h>
using namespace std;
//Ìï¼ÉÈüÂí
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
	sort(nums1.begin(),nums1.end());
	vector<int> ind;
	for(int i = 0; i<nums2.size(); i++) ind.push_back(i);
	sort(ind.begin(),ind.end(),[&](int i , int j) {
		return nums2[i]<nums2[j];
	});

	int r = nums1.size()-1,i = 0;
	for(auto&& val:nums1) {
		if(val>nums2[ind[i]]) {
			nums2[ind[i]] = val;
			i++;
		} else {
			nums2[ind[r]] = val;
			r--;
		}
	}

	return nums2;
}



int main() {
	vector<int>	nums1 {718967141,189971378,341560426,23521218,339517772},
	       nums2 {967482459,978798455,744530040,3454610,940238504};
	vector<int>	res = advantageCount(nums1,nums2);
	for(auto&& val:res) {
		cout<<val<<" ";
	}
}
