/*
1��ʯ�Ӻϲ�
��һ��Բ�βٳ������ܰڷ���n��ʯ��(n<= 100)����Ҫ��ʯ���д���غϲ���һ�ѡ�
�涨ÿ��ֻ��ѡȡ���ڵ����Ѻϲ����µ�һ��,�����µ�һ�ѵ�ʯ����,��Ϊ�ôκϲ��ĵ÷֡�
��һ�������ļ������ջ��n��ÿ��ջ��ʯ����(<=20)��
ѡ��һ�ֺϲ�ʯ�ӵķ���,ʹ����n��1�κϲ�,�÷ֵ��ܺ���С��
�������ݣ�
��һ��Ϊʯ�Ӷ���n��
�ڶ���Ϊÿ�ѵ�ʯ����,ÿ������֮����һ���ո�ָ���
������ݣ�
�ӵ�һ����n��Ϊ�÷���С�ĺϲ���������n+1���ǿ���.�ӵ�n+2�е���2n+1���ǵ÷����ϲ�������
ÿ�ֺϲ�������n�б�ʾ�����е�i��(1<=i<=n)��ʾ��i�κϲ�ǰ���ѵ�ʯ����(��˳ʱ������������һ�����������)��
Ҫ�󽫴��ϲ�������ʯ��������Ӧ�ĸ�����ʾ��
Sample Input
4
4 5 9 4
Sample Output
��4 5 9 ��4
��8 ��5 9
��13 ��9
22 4 ��5 ��9 4
4 ��14 ��4
��4 ��18
22
������
��dp[i][k]��ʾ��iΪ��㣬����Ϊk��ֱ���ϸ���ʯ�ӵ����źϲ�״̬
  sum[i][k]��ʾ��iΪ��㣬����Ϊk��ֱ���ϸ���ʯ�ӵ��ܷ�
  ö����㣬�价Ϊֱ��
 
  ����ÿһ������Ϊk��ֱ����k-1�ֻ��ַ�����
                   ö�ٺ󣬾��������ֵ
  �磺4 4 5 9,�����Ѿ��ϲ����һ����ѣ�����3�ֻ��֣���
  4 459;44 59;445 9;�����������������ÿ�����ѵĺϲ�
  dp[1][4]=dp[1][1]+dp[2][3]+sum[1][4]
          =dp[1][2]+dp[3][2]+sum[1][4]
          =dp[1][3]+dp[4][1]+sum[1][4]
  �����������Ʒֽ�
  dp[2][3]=dp[2][1]+dp[3][2]+sum[2][3]
          =dp[2][2]+dp[][]+sum[2][3]
  dp[2][2]=dp[2][1]+dp[3][1]+sum[2][2]
  dp[1][2]=dp[1][1]+dp[2][1]+sum[1][2]
  dp[3][2]=dp[3][1]+dp[4][1]+sum[3][2]
  dp[1][3]=dp[1][1]+dp[2][2]+sum[1][3]
          =dp[1][2]+dp[3][1]+sum[1][3]
  ��dp[1][1]=4;dp[2][1]=4;dp[3][1]=5;dp[4][1]=9;
  ���ϵݹ����µ��ƶ����������ֵ
  Ҳ����Ҫ��dp[][]��sum[][]�����ű���д���
  ���ռ��裬�����ű�Ҫ��������
 *//**/

#include<stdio.h>
#include<iostream>
using namespace std;
int dp[100][100] = { 0 };
int weath[100] = { 0 };
int sum[100][100] = { 0 };
int n = 0;
void set() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> weath[i];
    }
    for (int i = 1; i <= n; i++) {
        sum[i][1] = weath[i];
    }
    for (int i = 2; i <= n; i++) {//��������n��
        for (int j = 1; j <= n; j++) {
            sum[j][i] = sum[j % n + 1][i - 1] + sum[j][1];// sum[j][i]��ʾ��jΪ��㣬����Ϊi��ֱ���ϸ���ʯ�ӵ��ܷ�
        }
    }
}
int Max(int s,int l){
    int temp = 0;
    if (dp[s][l]!=-1)
        return dp[s][l];
    dp[s][l] = 0;
    for (int i = 1; i < l; i++) {
        temp = Max(s, i) + Max((s + i - 1 )% n + 1, l - i) + sum[s][l];
        if (temp > dp[s][l]) {
            dp[s][l] = temp;
        }
    }
    return dp[s][l];
}
int Min(int s, int l) {
    int temp = 0;
    if (dp[s][l]!=-1)
        return dp[s][l];
    dp[s][l] = 100000;
    if (l == 1) {
        dp[s][l] = 0;
    }
    for (int i = 1; i < l; i++) {
        temp = Min(s, i) + Min((s + i - 1) % n + 1, l - i) + sum[s][l];
        if (temp < dp[s][l]) {
            dp[s][l] = temp;
        }
    }
    return dp[s][l];
}
int main(void) {
    int temp1, temp2, min = 10000, max = 0,memmaxi=0,memmini=0;
    set();
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        
        temp2 = Min(i, n);
        if (temp2 < min) {
            min = temp2;
            memmini = i;
        }
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
    temp1 = Max(i, n);
    if (temp1 > max) {
        max = temp1;
        memmaxi = i;
    }
    }
    cout << "--------------" << endl;
    cout << max  << endl;
    cout << "---------------" << endl;
    cout << min  << endl;
    return 0;
}

