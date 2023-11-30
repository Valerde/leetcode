/*
一农场由图所示的十一种小方块组成，蓝色线条为灌溉渠。若相邻两块的灌溉渠相连则只需一口水井灌溉。
给出若干由字母表示的最大不超过50×50具体由(m，n)表示，的农场图，编程求出最小需要打的井数。
每个测例的输出占一行。当M=N=-1时结束程序。
2 2
DK
HF
3 3
ADC
FJK
IHE
-1 -1
*/

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
void set_canal(int a[][4]) {
	a[0][0] = a[0][1] = 1;
	a[1][1] = a[1][2] = 1;
	a[2][0] = a[2][3] = 1;
	a[3][2] = a[3][3] = 1;
	a[4][1] = a[4][3] = 1;
	a[5][0] = a[5][2] = 1;
	a[6][0] = a[6][1] = a[6][2] = 1;
	a[7][0] = a[7][1] = a[7][3] = 1;
	a[8][0] = a[8][2] = a[8][3] = 1;
	a[9][1] = a[9][2] = a[9][3] = 1;
	a[10][0] = a[10][1] = a[10][2] = a[10][3] = 1;
}
void set_canal_now(vector<vector<int> >& a,int row,int col) {
	char b;
	scanf_s("%c", &b, 1);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf_s("%c", &b, 1);
			a[i][j] = b - 65;
		}
		scanf_s("%c",&b,1);
	}

}
//a里面存的是字母对应的数字
void count_recursion(vector<vector<int> >& a, int row, int b[][4], int col, vector<vector<int> >& flag,int i,int j) {
	if (flag[i][j] == 0&&(i>=0&&i<row)&&(0<=j&&j<col)) {
		flag[i][j] = 1;
		if(i<row-1)
			if(b[a[i][j]][3]==1&&b[a[i+1][j]][1]==1)
				count_recursion(a, row, b, col, flag, i+1, j);
		if(i>0)
			if(b[a[i][j]][1]==1&&b[a[i-1][j]][3]==1)
				count_recursion(a, row, b, col, flag, i -1, j);
		if(j>0)
			if (b[a[i][j]][0] == 1 && b[a[i][j-1]][2] == 1)
				count_recursion(a, row, b, col, flag, i , j-1);
		if(j<col-1)
			if (b[a[i][j]][2] == 1 && b[a[i][j+1]][0] == 1)
				count_recursion(a, row, b, col, flag, i , j+1);
	}
	

}
int countl(vector<vector<int> >& a, int row, int col, int b[][4]) {
	int i, j,count=0;
	vector<vector<int> > flag(row, vector<int>(col));
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			flag[i][j] = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (flag[i][j] == 0) {
				count++;
				count_recursion(a, row, b, col, flag, i, j);
			}
		}
	}
	return count;
}
int main(void) {
	int a[11][4] = { 0 };
	set_canal(a);
	int row, col;
	cin >> row >> col;
	while (row != -1 && col != -1) {
		vector<vector<int> > b(row, vector<int>(col));
		set_canal_now(b, row, col);
		int count_jing = countl(b, row, col, a);
		cout << count_jing << endl;
		cin >> row >> col;
	}
	return 0;
}



