/*
2．最小代价子母树
设有一排数，共ｎ个，例如：22 14 7 13 26 15 11。任意2个相邻的数可以进行归并，归并的代价为该两个数的和,经过不断的归并，最后归为一堆，而全部归并代价的和称为总代价，给出一种归并算法，使总代价为最小。
输入、输出数据格式与“石子合并”相同。
Sample Input
4
12 5 16 4
Sample Output
－12 －５ 16 ４
１７ －16 －４
－17 －20
37
*/

/*
* 分析：
* 本道题与第一道题类似，反而比第一到题稍微简单一点
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






