/*
����һ���±�� 0?��ʼ����������?nums?��һ������?pivot?�����㽫?nums?�������У�ʹ������������������

����С��?pivot?��Ԫ�ض����������д���?pivot?��Ԫ��?֮ǰ?��
���е���?pivot?��Ԫ�ض�������С�ںʹ��� pivot?��Ԫ�� �м�?��
С�� pivot?��Ԫ��֮��ʹ��� pivot?��Ԫ��֮��� ���˳��?�������ı䡣
����ʽ�ģ�����ÿһ��?pi��pj?��pi?�ǳ�ʼʱλ�� i?Ԫ�ص���λ�ã�pj?�ǳ�ʼʱλ��?j?Ԫ�ص���λ�á�����С��?pivot?��Ԫ�أ����?i < j?��?nums[i] < pivot ��?nums[j] < pivot?����������ô?pi < pj?Ҳ���������Ƶģ����ڴ���?pivot?��Ԫ�أ����?i < j ��?nums[i] > pivot ��?nums[j] > pivot?����������ô?pi < pj?��
���㷵���������� nums?�����Ľ�����顣

*/

#include<bits/stdc++.h>
using namespace std;
vector<int> pivotArray(vector<int>& nums, int pivot) {
	int n = nums.size();

	vector<int> res (n,pivot);
	int left = 0,right = n - 1;

	for(int i = 0; i<n; i++) {
		if(nums[i]<pivot) {
			res[left] = nums[i];
			left++;
		} else if(nums[i]>pivot) {
			res[right]=nums[i];
			right--;
		}
	}
	reverse(res.begin()+right+1,res.end());
	return res;
}
int main() {
	vector<int> nums {9,12,5,10,14,3,10};
	vector<int> res = pivotArray(nums,10);
	for(auto&& val:res)
		cout<<val<<" ";
}
