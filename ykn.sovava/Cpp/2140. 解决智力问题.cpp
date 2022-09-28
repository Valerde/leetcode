#include<bit/stdc++.h>
using namespace std;

/**
用dp[i] 表示解决第i道题目以及以后获得的最大分数, 选择从后往前遍历
如果不解决某一道题目 , 那么dp[i] = dp[i+1]
dp[i] = dp[i+brainpower+1] + points[i]
状态转移方程为: dp[i] = max(dp[i+brainpower+1] + points[i] ,dp[i+1] )

边界条件: 用dp[n] = 0 ; 来表示超过了最后 , 没有做任何题目
那么 ,  dp[i] = max(dp[max(i+brainpower+1,n)] + points[i] ,dp[i+1] )
那么dp [0] 即为最后的答案

 */

long long mostPoints(vector<vector<int>>& questions) {
	int n = questions.size();
	long long dp[n+1] = {0};
	for(int i = n-1; i>=0; i--) {
		dp[i] =  max(dp[min(i+questions[i][1]+1,n)] + questions[i][0] ,dp[i+1] );
	}
	return dp[0];
}

int main() {

}

