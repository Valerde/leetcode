#include<bis/stdc++.h>
using namespace std;

/*
������������������Ҳ�Ϊ�յ���������?nums1?��?nums2?����һ�β����У����ǿ��Խ���?nums1[i]?��?nums2[i]��Ԫ�ء�

���磬��� nums1 = [1,2,3,8] �� nums2 =[5,6,7,4] ������Խ��� i = 3 ����Ԫ�أ��õ� nums1 =[1,2,3,4] �� nums2 =[5,6,7,8] ��
���� ʹ nums1 �� nums2 �ϸ����?�����������С���� ��

����arr�ϸ���� ��arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1]?��

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
