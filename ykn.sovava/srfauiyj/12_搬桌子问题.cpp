/*
ĳ��ѧ��¥һ����n�����ң����������α��Ϊ1��2������n��
����Ҫ��һЩ������ĳЩ���Ұᵽ����һЩ���ң�ÿ�����Ӷ��Ǵӱ�Ž�С�Ľ��Ұᵽ��Žϴ�Ľ��ң�
ÿһ�ˣ����Ǵ������ߣ�����һ�ſ����󣬿��Լ����ӵ�ǰλ�û������߰���һ�����ӡ�
�������ݣ�������n��m��Ȼ�������m��������m��Ҫ���������ʼ���Һ�Ŀ����ҡ�������ݣ�������Ҫ�ܼ��ˡ�
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
		mov[j] = k;           //mov ���ߵ�n
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