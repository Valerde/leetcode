#include<bits/stdc++.h>
using namespace std;



int MOD = 1000000007;
int sumSubarrayMins(vector<int>& arr) {
	int n = arr.size();
	if(n == 0||n == 1) return n* (n==1?arr[0]:0);

	long res = 0;
	stack<int> stk;
	vector<int > left(n);
	vector<int>  right(n);
	//左边界
	for(int i = 0; i<n; i++) {
		int num = arr[i];
		while(!stk.empty()&&num<arr[stk.top()]) {
			stk.pop();
		}
		left[i] = stk.empty()?-1:stk.top();
		stk.push(i);
	}
	stack<int>().swap(stk);
	//右边界
	for(int i = arr.size()-1; i>=0; i--) {
		int num = arr[i];
		while(!stk.empty()&&num<=arr[stk.top()]) {
			stk.pop();
		}
		right[i] = stk.empty()?n:stk.top();
		stk.push(i);
	}

	for(int i = 0; i<n; i++) {
		res=(res+(arr[i]*(long)(i-left[i])*(right[i]-i)))%MOD;
	}
	return (int)res;
}



//------------------------------------------------------

int getElement(vector<int>& arr, int n, int i) {
	if (i == -1 || i == n) {
		return INT_MIN;
	}
	return arr[i];
}

int sumSubarrayMins(vector<int>& arr) {
	// 处理边界情况
	if (arr == null || arr.length == 0) {
		return 0;
	}
	int n = arr.length;
	long ans = 0;
	stack<int> stack;
	// 将下标-1和n作为两个哨兵元素，它们对应的元素为MIN_VALUE
	// -1作为最左边界，n作为最右边界
	for (int i = -1; i <= n; i++) {
		// 向左寻找第一个小于等于A[i]的元素
		while (!stack.empty() && getElement(arr, n, stack.top()) > getElement(arr, n, i)) {
			// A[cur]就是之前思路中的A[i]，注意区分和上面代码的区别
			// 对于每个出栈元素来说，i就是它们的右边界，而栈顶元素就是左边界
			int cur = stack.pop();
			// 计算贡献值
			ans = (ans + (long)(cur - stack.top()) * (i - cur) * arr[cur]) % MOD;
		}
		stack.push(i);
	}

	return (int)ans;
}

//作者：yimeixiaobai
//链接：https://leetcode.cn/problems/sum-of-subarray-minimums/solution/xiao-bai-lang-dong-hua-xiang-jie-bao-zhe-489q/

