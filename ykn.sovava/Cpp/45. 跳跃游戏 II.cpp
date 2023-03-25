#include<bits/stdc++.h>
using namespace std;

//ֻ��Ҫ��һ�� ��Ծ ���ʱ��������һ�� ��������Զ�ľ��롣
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
int jump2(vector<int>& nums){
int end = 0;
int step = 0;
int maxPosition = 0;
for(int i = 0;i<nums.size()-1;i++){
maxPosition = max(i+nums[i],maxPosition);
if(i == end){
end = Position;
step++;}}
return maxPosition;}

