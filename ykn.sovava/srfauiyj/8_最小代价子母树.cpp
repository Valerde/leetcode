/*
2����С������ĸ��
����һ����������������磺22 14 7 13 26 15 11������2�����ڵ������Խ��й鲢���鲢�Ĵ���Ϊ���������ĺ�,�������ϵĹ鲢������Ϊһ�ѣ���ȫ���鲢���۵ĺͳ�Ϊ�ܴ��ۣ�����һ�ֹ鲢�㷨��ʹ�ܴ���Ϊ��С��
���롢������ݸ�ʽ�롰ʯ�Ӻϲ�����ͬ��
Sample Input
4
12 5 16 4
Sample Output
��12 ���� 16 ��
���� ��16 ����
��17 ��20
37
*/

/*
* ������
* ���������һ�������ƣ������ȵ�һ������΢��һ��
* dp[1][4]=dp[1][1]+dp[2][3]+sum[1][4]
*         =dp[1][2]+dp[3][2]+sum[1][4]
*         =dp[1][3]+dp[4][1]+sum[1][4]

*/

#include <cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int sum[20][20] = { 0 };
int dp[20][20] = { 0 };
int wealth[20] = { 0 };
int n = 0;
int flag[20][20] = { 0 };
int cnt;
void setmy() {
	cin >> n;
	cnt = n;
	for (int i = 1; i <= n; i++) {
		cin >> wealth[i];
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= n; i++) {
		sum[i][1] = wealth[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - 1 && i + j <= n + 1; j++)
			sum[j][i] += sum[j + 1][i - 1] + sum[j][1];
	}
}
int Min(int s, int l) {
	if (dp[s][l] != -1) {
		return dp[s][l];
	}
	int temp=0;
	cnt--;//--------------------
	dp[s][l] = 10000;
	if (l == 1) {
		dp[s][1] = 0;
		return 0;
	}
	for (int i = 1; i < l; i++) {
		temp = Min(s,i) + Min(s + i,l - i) + sum[s][l];
		
		if (temp < dp[s][l]) {
			dp[s][l] = temp;
		}
	}
	return dp[s][l];
}
int main(void) {
	setmy();
	cout << Min(1, n);
	return 0;
}



/*
for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}
*/






