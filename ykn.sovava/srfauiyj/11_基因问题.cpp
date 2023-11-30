/*
5．*基因问题
已知两个基因序列如s：AGTAGT；t：ATTAG。现要你给序列中增加一些空格后，首先使得两个序列的长度相等，
其次两个串对应符号匹配得到的值最大。基因只有四种分别用A、G、C、T表示，匹配中不允许两个空格相对应，
任意两符号的匹配值由下表给出：
	A	G	C	T	︺
A	5	-2	-1	-2	-4
G	-2	5	-4	-3	-2
C	-1	-4	5	-5	-1
T	-2	-3	-5	5	-2
︺	-4	-2	-1	-2

*/
/*
* 这道题是最大公共子序列的升级版，同样是从最后一个开始匹配
* mv[i],[j]表示 s 串的前 i 个碱基和 t 串的前 j 个碱基的相似度match value
* 不同的是最后有三种情况
* 1.碱基与碱基匹配
* 2.碱基与空格匹配
* 3.空格与碱基匹配
* 则状态转移方程为mv[i][j]=max(mv[i][j],mv[i-1][j]+w[s[i]][k],mv[i][j-1]+w[k][t[j]])
* 其中s[i],t[j]为s,t,串中第i,j个字母，w为匹配值，k为空格
* 
* 边界条件：递推到一条没了以后那么,mv[i][0]=mv[i-1][0]+w[s[i]][k],或mv[0][j]=mv[0][j-1]+w[k][t[j]]
* 双方都完了那么f[0][0]=0;
* 
* 为了简化输入，提前输好每个串的长度

*/
//#include<iostream>
//#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int lens = 0, lent = 0, k = 5;
int w[6][6] = {
	{0,0,0,0,0,0},
	{0,5,-2,-1,-2,-4},
	{0,-2,5,-4,-3,-2},
	{0,-1,-4,5,-5,-1},
	{0,-2,-3,-5,5,-2},
	{0,-4,-2,-1,-2,0}
};
struct Mem {
	int s;
	int t;
};
//Mem mem[30][30];
int s[200] = { 0 };
int t[200] = { 0 };
int mv[200][200] = { 0 };
void setmy() {
	cin >> lens>>lent;
	char a;
	for (int i = 1; i <= lens; i++) {
		cin >> a;
		switch(a){
			case 'A':s[i] = 1; break;
			case 'G':s[i] = 2; break;
			case 'C':s[i] = 3; break;
			case 'T':s[i] = 4; break;
		}
	}
	for (int i = 1; i <= lent; i++) {
		cin >> a;
		switch (a) {
		case 'A':t[i] = 1; break;
		case 'G':t[i] = 2; break;
		case 'C':t[i] = 3; break;
		case 'T':t[i] = 4; break;
		}
	}
}

void solution() {
	mv[0][0] = 0;
	for (int i = 1; i <= lens; i++) {
		mv[i][0] = mv[i - 1][0] + w[s[i]][k];
	}
	for (int j = 1; j <= lent; j++) {
		mv[0][j] = mv[0][j - 1] + w[k][t[j]];
	}
	for (int i = 1; i <= lens; i++)
		for (int j = 1; j <= lent; j++) {
			mv[i][j] = max(max(mv[i-1][j-1]+w[s[i]][t[j]], mv[i - 1][j] + w[s[i]][k]), mv[i][j - 1] + w[k][t[j]]);
		}
	

	printf("%d", mv[lens][lent]);

}
int main(void) {
	setmy();
	solution();
	return 0;
}
