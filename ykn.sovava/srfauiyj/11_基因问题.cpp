/*
5��*��������
��֪��������������s��AGTAGT��t��ATTAG����Ҫ�������������һЩ�ո������ʹ���������еĳ�����ȣ�
�����������Ӧ����ƥ��õ���ֵ��󡣻���ֻ�����ֱַ���A��G��C��T��ʾ��ƥ���в����������ո����Ӧ��
���������ŵ�ƥ��ֵ���±������
	A	G	C	T	��
A	5	-2	-1	-2	-4
G	-2	5	-4	-3	-2
C	-1	-4	5	-5	-1
T	-2	-3	-5	5	-2
��	-4	-2	-1	-2

*/
/*
* ���������󹫹������е������棬ͬ���Ǵ����һ����ʼƥ��
* mv[i],[j]��ʾ s ����ǰ i ������� t ����ǰ j ����������ƶ�match value
* ��ͬ����������������
* 1.�������ƥ��
* 2.�����ո�ƥ��
* 3.�ո�����ƥ��
* ��״̬ת�Ʒ���Ϊmv[i][j]=max(mv[i][j],mv[i-1][j]+w[s[i]][k],mv[i][j-1]+w[k][t[j]])
* ����s[i],t[j]Ϊs,t,���е�i,j����ĸ��wΪƥ��ֵ��kΪ�ո�
* 
* �߽����������Ƶ�һ��û���Ժ���ô,mv[i][0]=mv[i-1][0]+w[s[i]][k],��mv[0][j]=mv[0][j-1]+w[k][t[j]]
* ˫����������ôf[0][0]=0;
* 
* Ϊ�˼����룬��ǰ���ÿ�����ĳ���

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
