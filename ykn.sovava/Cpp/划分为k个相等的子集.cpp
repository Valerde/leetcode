#include<bits/stdc++.h>
using namespace std;

bool canPartitionKSubsets1(vector<int>& nums, int k) {
	int all = accumulate(nums.begin(),nums.end(),0);
	if(all%k>0) {
		return false;
	}

	int per = all/k;
	sort(nums.begin(),nums.end());
	if(nums.back()>per) {
		return false;
	}

	int n = nums.size();
	vector<bool> dp(1<<n,false);
	vector<int> curSum(1<<n,0);
	dp[0] = true;
	for(int i = 0; i<1<<n; i++) {
		if(!dp[i]) {
			continue;
		}
		for(int j = 0; j<n; j++) {
			if(curSum[i]+nums[j]>per) {
				break;
			}
			if(((i>>j)&1)==0) {
				int next = i|(1<<j);
				if(!dp[next]) {
					curSum[next] = (curSum[i]+nums[j])%per;
					dp[next] = true;
				}
			}

		}
	}
	return dp[(1<<n)-1];
}


bool reverse(int* nums, int numsSize, int k, int target, int* tmpArr, int index) {
	if (index == numsSize) {//所有元素的枚举完了
		for (int i = 0; i < k; i++) {//判断是否每个桶都装满了
			if (tmpArr[i] != target) {
				return false;
			}
		}
		return true;
	}
	for (int i = 0; i < k; i++) {//枚举每一个桶
		if (tmpArr[i] + nums[index] > target) {//当前桶装不下了。下一个去
			continue;//剪枝
		}
		tmpArr[i] += nums[index];//装了
		if (reverse(nums, numsSize, k, target, tmpArr, index + 1)) {
			return true;//判断当前桶装了之后，下一个是否还能正常装好
		}
		tmpArr[i] -= nums[index];//下一个不能，说明这个球不是这个桶的，回溯
		//如果第一个球，在第一个桶里面装不了，那么因为所有桶都是一样的，
		//其他桶肯定也装不了，提前结束
		if (tmpArr[i] == 0) {//再剪枝
			break;
		}
	}
	return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k) {

	// 计算每个子集的和
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}

	if (sum % k != 0) {
		return false;
	}
	int target = sum / k;

	int tmpArr[k];
	memset(tmpArr, 0, sizeof(int) * k);

	return reverse(nums, numsSize, k, target, tmpArr, 0);
}

bool rev(vector<int>& nums,int numsize, int k,int target,int* tmpArr,int index) {
	if(index==numsize) {
		for(int i = 0; i<k; i++) {
			if(tmpArr[i]!=target) {
				return false;
			}
		}
		return true;
	}


	for(int i = 0; i<k; i++) {

		if(tmpArr[i]+nums[index]>target) continue;
		tmpArr[i]+=nums[index];
		if(rev(nums,numsize,k,target,tmpArr,index+1)) {
			return true;
		}

		tmpArr[i]-=nums[index];
		if(tmpArr[i]==0) {
			break;
		}
	}
	return false;



}


bool canPartitionKSubset2(vector<int>& nums, int k) {
	int all = accumulate(nums.begin(),nums.end(),0);
	if(all%k>0) {
		return false;
	}
	int target = all/k;
	int numsize = nums.size();
	int tmpArr[17]={0}; //k个集合
	return rev(nums,numsize,k,target,tmpArr,0);
}
int main() {
	vector<int> nums {4,3,2,3,5,2,1};
	int k=4;
	//int nums[7] = {4,3,2,3,5,2,1};
	bool flag = canPartitionKSubset2(nums,k);
	cout<<flag;
}
