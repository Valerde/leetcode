/*
给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？

以任意顺序返回这两个数字均可。
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> missingTwo(vector<int>& nums) {

	int xornum = 0 ;
	for(int i = 1; i<=nums.size()+2; i++)		xornum^=i;
	for(auto a:nums) xornum^=a;
	//此时 x1^x2==xornum

	int lsb = xornum&(-xornum);//lsb 为xornum最低的1

	//那么lsb和1~N的所有与或 , 就有0与非0两种结果
	//在1的一组中,必定只能找到一个(因为xornum&-xornum^x1 == x1^x2&-(x1^x2)^x1 == x2&-(x1^x2)  )
	int type = 0;
	for(int i = 1; i<=nums.size()+2; i++)
		if(lsb&i)	type^=i;

	for(auto a:nums) {
		if(lsb&a) type^=a;
	}
	vector<int> v {type,type^xornum};
	return v;
}

int main() {
	vector<int> nums {2,3};
	vector<int> res = missingTwo(nums);

//	cout<<res[1]<<" " <<res[0];

	int x1 = 3,x2 = 4;//x1 = 11 , x2 100
	int r = x2&(-(x1^x2));
	cout<<r;
}
