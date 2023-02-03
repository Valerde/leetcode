#include<bits/stdc++.h>
using namespace std;


string minNumber(vector<int>& nums) {
	vector<string> strs;
	for(auto&& num:nums) {
		strs.push_back(to_string(num));
	}
	quickSort(strs,0,strs.size()-1);
	string res;
	for(string str:strs) res.append(str);
	return res;
}

void quickSort(vector<string>& strs,int left,int right) {
	if(left>right) return ;
	int i = left , j = right;
	while(i < j) {
		while(strs[j]+strs[left]>=strs[left]+strs[j] && i < j) j--;
		while(strs[i] + strs[left] <= strs[left] + strs[i] && i < j) i++;
		swap(strs[i] , strs[j]);
	}
	swap(strs[i] , strs[l]);
	quickSort(strs,left,i-1);
	quickSort(strs,i+1,right);
}
