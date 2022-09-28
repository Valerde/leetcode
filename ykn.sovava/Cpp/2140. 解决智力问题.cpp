#include<bit/stdc++.h>
using namespace std;

/**
��dp[i] ��ʾ�����i����Ŀ�Լ��Ժ��õ�������, ѡ��Ӻ���ǰ����
��������ĳһ����Ŀ , ��ôdp[i] = dp[i+1]
dp[i] = dp[i+brainpower+1] + points[i]
״̬ת�Ʒ���Ϊ: dp[i] = max(dp[i+brainpower+1] + points[i] ,dp[i+1] )

�߽�����: ��dp[n] = 0 ; ����ʾ��������� , û�����κ���Ŀ
��ô ,  dp[i] = max(dp[max(i+brainpower+1,n)] + points[i] ,dp[i+1] )
��ôdp [0] ��Ϊ���Ĵ�

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

