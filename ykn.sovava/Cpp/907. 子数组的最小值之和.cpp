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
	//��߽�
	for(int i = 0; i<n; i++) {
		int num = arr[i];
		while(!stk.empty()&&num<arr[stk.top()]) {
			stk.pop();
		}
		left[i] = stk.empty()?-1:stk.top();
		stk.push(i);
	}
	stack<int>().swap(stk);
	//�ұ߽�
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
	// ����߽����
	if (arr == null || arr.length == 0) {
		return 0;
	}
	int n = arr.length;
	long ans = 0;
	stack<int> stack;
	// ���±�-1��n��Ϊ�����ڱ�Ԫ�أ����Ƕ�Ӧ��Ԫ��ΪMIN_VALUE
	// -1��Ϊ����߽磬n��Ϊ���ұ߽�
	for (int i = -1; i <= n; i++) {
		// ����Ѱ�ҵ�һ��С�ڵ���A[i]��Ԫ��
		while (!stack.empty() && getElement(arr, n, stack.top()) > getElement(arr, n, i)) {
			// A[cur]����֮ǰ˼·�е�A[i]��ע�����ֺ�������������
			// ����ÿ����ջԪ����˵��i�������ǵ��ұ߽磬��ջ��Ԫ�ؾ�����߽�
			int cur = stack.pop();
			// ���㹱��ֵ
			ans = (ans + (long)(cur - stack.top()) * (i - cur) * arr[cur]) % MOD;
		}
		stack.push(i);
	}

	return (int)ans;
}

//���ߣ�yimeixiaobai
//���ӣ�https://leetcode.cn/problems/sum-of-subarray-minimums/solution/xiao-bai-lang-dong-hua-xiang-jie-bao-zhe-489q/

