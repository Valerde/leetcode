/*
某教学大楼一层有n个教室，从左到右依次编号为1、2、…、n。
现在要把一些课桌从某些教室搬到另外一些教室，每张桌子都是从编号较小的教室搬到编号较大的教室，
每一趟，都是从左到右走，搬完一张课桌后，可以继续从当前位置或往右走搬另一张桌子。
输入数据：先输入n、m，然后紧接着m行输入这m张要搬课桌的起始教室和目标教室。输出数据：最少需要跑几趟。
Sample Input
10  5
1  3
3  9
4  6
6  10
7  8
Sample Output
3
*/
#include<iostream>
#include<algorithm>
using namespace std;
//int cr[100] = { 0 };
int mov[100] = { 0 };
int n,m;
void set() {
	cin >> n>>m;
	int j = 0, k = 0;
	for (int i = 0; i < m; i++) {
		cin >> j >> k;
		mov[j] = k;           //mov 上线到n
	}
}
void solution(int i) {
	int j=0;
	for (i; i <= n; i++) {

		if (mov[i] != 0) {
			j = mov[i];
			mov[i] = 0;
			if (j <= n)
				solution(j);
			break;
		}
	}
}

int main(void) {
	set();
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (mov[i] != 0) {
			c++;
			solution(i);
		}
	}
	cout << c;
	return 0;
}