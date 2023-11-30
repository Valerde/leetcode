#include<iostream>
#include<malloc.h>
#define N 5
using namespace std;
void max(int **a, int m, int& row, int& col) {  //N为常量，m为数组二维数组a的行数
	int i,j,maxl=a[0][0];
	row = col = 0;
	for(i=0;i<m;i++)
		for (j = 0; j < N; j++) {
			if (maxl < a[i][j]) {
				maxl = a[i][j];
				row = i;
				col = j;
			}
		}
}

int main(void) {
	int m,row,col;
	cout << "enter the m: ";
	cin >> m;
	int** a;
	a = (int** )calloc(m, sizeof(int*));
	if (!a) return 0;
	int i, j;
	for (i = 0; i < m; i++) {
		a[i] = (int*)calloc(N, sizeof(int));
		if (a[i] == NULL) return 0;
	}
	for (i = 0; i < m; i++)
		for (j = 0; j < N; j++)
			cin >> a[i][j] ;
	max(a, m, row, col);
	cout << row +1<<" "<< col+1 << endl;
	return 0;
}