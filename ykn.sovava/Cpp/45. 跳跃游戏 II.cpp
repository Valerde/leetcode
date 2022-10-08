#include<bits/stdc++.h>
using namespace std;

//只需要在一次 跳跃 完成时，更新下一次 能跳到最远的距离。
int jump(vector<int>& nums) {
	int end = 0;
	int step = 0;
	int maxPosition = 0;
	for(int i = 0; i < nums.size()-1; i++) {
		maxPosition = max(i+nums[i],maxPosition);
		if(i == end) {
			end = maxPosition;
			step++;
		}
		
	}
	return step;
}
