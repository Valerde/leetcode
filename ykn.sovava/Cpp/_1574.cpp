#include<bits/stdc++.h>
using namespace std;
int findLengthOfShortestSubarray(vector<int> &arr) {
	int len = arr.size();
	int l = 0,r=len-1;
	while(r>0&&arr[r-1]<=arr[r]) r--;
	if(r==0) return 0;
	int ans = 0;
	for(l=0; l==0||arr[l]<=arr[l+1]; l++) {
		while(arr[l]>arr[r]) r++;
		ans = min(ans,r-l+1);
	}
	return ans;
}
