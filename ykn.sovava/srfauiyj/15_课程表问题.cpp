/*
4.课程表
这里有 n 门不同的在线课程，他们按从 1 到 n 编号。每一门课程有一定的持续上课时间（课程时间）t 以及关闭时间第 d 天。
一门课要持续学习 t 天直到第 d 天时要完成，你将会从第 1 天开始。
给出 n 个在线课程用 (t, d) 对表示。你的任务是找出最多可以修几门课（你不能同时修两门课程）。
输入：n和n对数据（t，d）
输出：最多可以修多少门课
样例：
输入：4 [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
输出：3
样例解释：
这里一共有 4 门课程, 但是你最多可以修 3 门:
首先, 修第一门课时, 它要耗费 100 天，你会在第 100 天完成, 在第 101 天准备下门课。
第二, 修第三门课时, 它会耗费 1000 天，所以你将在第 1100 天的时候完成它, 以及在第 1101 天开始准备下门课程。
第三, 修第二门课时, 它会耗时 200 天，所以你将会在第 1300 天时完成它。
第四门课现在不能修，因为你将会在第 3300 天完成它，这已经超出了关闭日期。

*/

/*
* 分析：
* 先按结束时间排序，再依次选择
* 如果已上课时间加上该次课程时间<该课结束时间则选择上。
* 如果只用谈心的话，如果出现3   6 7，3 8,5 8这样的数据，输出结果为1，但是明显结果应该是2，所以应该有所改进。
* 即在已经选择的课程中将时间最长的与该课程时间比较，如果该课程时间较短则替换

*/

#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct Data {
	int t;
	int d;
};
Data dat[100];
int flag[100] = { 0 };
bool cmp(Data x, Data y) {
	return x.d < y.d;
}
int find(int n) {
	int temp=0,tempi=0;
	for (int i = 0; i < n+1; i++) {
		if (temp < dat[i].t && flag[i]==1) {
			temp = dat[i].t;
			tempi = i;
		}
	}
	return tempi;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dat[i].t >> dat[i].d;
	}
	//-----------输入完毕
	sort(dat, dat + n, cmp);

	int tl=0,temp=0,tempi=0,cnt=0;
	for (int i = 0; i < n; i++) {
		
		tl += dat[i].t;
		flag[0] = 1;
		if (tl <= dat[i].d) {
			flag[i]=1;
			tempi = find(i);
			cnt++;
		}
		else {
			if (dat[tempi].t > dat[i].t) {
				tl -= dat[tempi].t;
				flag[tempi] = 0;
				flag[i] = 1;
				tempi = find(i);
			}
			else {
				tl -= dat[i].t;
			}
		}
	}
	cout << cnt;
}




