/*
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
输入：数组g和数组s
输出：最多能满足的孩子个数
样例：
输入：g = [1,2,3], s = [1,1]
输出：1
输入：g = [1,2], s = [1,2,3]
输出：2
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int g[100] = { 0 };
int s[100] = { 0 };
int leng, lens, countnum = 0;

void set() {
	int i;
	printf("输入胃口值g(以0结束)：");
	for ( i = 0; i<100; i++) {
		cin >> g[i];
		if (g[i] == 0) {
			break;
		}
	}
	leng = i;
	printf("输入饼干尺寸（以0结束）：");
	for ( i = 0; i<100; i++) {
		cin >> s[i];
		if (s[i] == 0) {
			break;
		}
	}
	lens = i;
}
void solution() {
	int j = 0;
	for (int i = 0; i < leng; i++) {
		for ( j ; j < lens; j++) {
			if (g[i] <= s[j] ) {
				countnum++;
				break;
			}
		}
	}
}
int main(void) {
	set();
	sort(s, s + lens);
	sort(g, g + leng);
	solution();
	cout << countnum << endl;
	return 0;
}
