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
	if (index == numsSize) {//����Ԫ�ص�ö������
		for (int i = 0; i < k; i++) {//�ж��Ƿ�ÿ��Ͱ��װ����
			if (tmpArr[i] != target) {
				return false;
			}
		}
		return true;
	}
	for (int i = 0; i < k; i++) {//ö��ÿһ��Ͱ
		if (tmpArr[i] + nums[index] > target) {//��ǰͰװ�����ˡ���һ��ȥ
			continue;//��֦
		}
		tmpArr[i] += nums[index];//װ��
		if (reverse(nums, numsSize, k, target, tmpArr, index + 1)) {
			return true;//�жϵ�ǰͰװ��֮����һ���Ƿ�������װ��
		}
		tmpArr[i] -= nums[index];//��һ�����ܣ�˵������������Ͱ�ģ�����
		//�����һ�����ڵ�һ��Ͱ����װ���ˣ���ô��Ϊ����Ͱ����һ���ģ�
		//����Ͱ�϶�Ҳװ���ˣ���ǰ����
		if (tmpArr[i] == 0) {//�ټ�֦
			break;
		}
	}
	return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k) {

	// ����ÿ���Ӽ��ĺ�
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
	int tmpArr[17]={0}; //k������
	return rev(nums,numsize,k,target,tmpArr,0);
}
int main() {
	vector<int> nums {4,3,2,3,5,2,1};
	int k=4;
	//int nums[7] = {4,3,2,3,5,2,1};
	bool flag = canPartitionKSubset2(nums,k);
	cout<<flag;
}
