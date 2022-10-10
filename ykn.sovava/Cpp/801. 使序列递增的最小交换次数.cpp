#include<bis/stdc++.h>
using namespace std;

/*
我们有两个长度相等且不为空的整型数组?nums1?和?nums2?。在一次操作中，我们可以交换?nums1[i]?和?nums2[i]的元素。

例如，如果 nums1 = [1,2,3,8] ， nums2 =[5,6,7,4] ，你可以交换 i = 3 处的元素，得到 nums1 =[1,2,3,4] 和 nums2 =[5,6,7,8] 。
返回 使 nums1 和 nums2 严格递增?所需操作的最小次数 。

数组arr严格递增 且arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1]?。

*/


int minSwap(vector<int>& nums1, vector<int>& nums2) {
	int a=0,b = 1;

	for(int i = 0; i<nums1.size(); i++) {
		int at = a,bt = b;
		a=b=n;
		if(nums1[i]>nums1[i-1]&&nums2[i]>nums2[i-1]) {
			a = min(a,at);
			b = min(b,bt)+1;
		}
		if(nums1[i]>nums2[i-1]&&nums2[i]>nums1[i-1]) {
			a = min(a , bt);
			b = min(b,at);
		}

	}
	return min(a,b);
}
