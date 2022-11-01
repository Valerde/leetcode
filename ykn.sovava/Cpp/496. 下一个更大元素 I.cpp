#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	
	vector<int> res(nums1.size());
	unordered_map<int,int> map;
	stack<int> stk;
	for(int i = nums2.size()-1;i>=0;i--){
		int num = nums2[i];
		while(!stk.empty()&&num>=stk.top()){
			stk.pop();
		}
		map[num]=stk.empty()?-1:stk.top();
		stk.push(num);
	}
	for(int i = 0;i< nums1.size();i++){
		res[i]=(map[nums1[i]]);
	}
	return res;
} 
