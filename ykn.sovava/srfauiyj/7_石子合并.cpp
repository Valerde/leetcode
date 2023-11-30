/*
1．石子合并
在一个圆形操场的四周摆放着n堆石子(n<= 100)，现要将石子有次序地合并成一堆。
规定每次只能选取相邻的两堆合并成新的一堆,并将新的一堆的石子数,记为该次合并的得分。
编一程序，由文件读入堆栈数n及每堆栈的石子数(<=20)。
选择一种合并石子的方案,使得做n－1次合并,得分的总和最小；
输入数据：
第一行为石子堆数n；
第二行为每堆的石子数,每两个数之间用一个空格分隔。
输出数据：
从第一至第n行为得分最小的合并方案。第n+1行是空行.从第n+2行到第2n+1行是得分最大合并方案。
每种合并方案用n行表示，其中第i行(1<=i<=n)表示第i次合并前各堆的石子数(依顺时针次序输出，哪一堆先输出均可)。
要求将待合并的两堆石子数以相应的负数表示。
Sample Input
4
4 5 9 4
Sample Output
－4 5 9 －4
－8 －5 9
－13 －9
22 4 －5 －9 4
4 －14 －4
－4 －18
22
分析：
设dp[i][k]表示以i为起点，长度为k的直线上各堆石子的最优合并状态
  sum[i][k]表示以i为起点，长度为k的直线上各堆石子的总分
  枚举起点，变环为直线
 
  对于每一条长度为k的直线有k-1种划分方法，
                   枚举后，就求出最优值
  如：4 4 5 9,看成已经合并后的一个大堆，共有3种划分，即
  4 459;44 59;445 9;看成是这三种情况下每两个堆的合并
  dp[1][4]=dp[1][1]+dp[2][3]+sum[1][4]
          =dp[1][2]+dp[3][2]+sum[1][4]
          =dp[1][3]+dp[4][1]+sum[1][4]
  子问题再类似分解
  dp[2][3]=dp[2][1]+dp[3][2]+sum[2][3]
          =dp[2][2]+dp[][]+sum[2][3]
  dp[2][2]=dp[2][1]+dp[3][1]+sum[2][2]
  dp[1][2]=dp[1][1]+dp[2][1]+sum[1][2]
  dp[3][2]=dp[3][1]+dp[4][1]+sum[3][2]
  dp[1][3]=dp[1][1]+dp[2][2]+sum[1][3]
          =dp[1][2]+dp[3][1]+sum[1][3]
  而dp[1][1]=4;dp[2][1]=4;dp[3][1]=5;dp[4][1]=9;
  从上递归或从下递推都能求得最优值
  也就是要把dp[][]和sum[][]这两张表填写完毕
  按照假设，这两张表要按列来填
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
    for (int i = 2; i <= n; i++) {//从两个到n个
        for (int j = 1; j <= n; j++) {
            sum[j][i] = sum[j % n + 1][i - 1] + sum[j][1];// sum[j][i]表示以j为起点，长度为i的直线上各堆石子的总分
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

