#include<bits/stdc++.h>
using namespace std;
/*
���ǳ�һ���� X Ϊ����, �������ÿλ��������ر���ת 180 �Ⱥ�
�����Կ��Եõ�һ����Ч�ģ��Һ� X ��ͬ������Ҫ��ÿλ���ֶ�Ҫ����ת��

���һ������ÿλ���ֱ���ת�Ժ���Ȼ����һ�����֣�?�����������Ч�ġ�
0, 1, �� 8 ����ת����Ȼ�������Լ���2 �� 5 ���Ի�����ת�ɶԷ���
����������£������Բ�ͬ�ķ�����ת�����仰˵��2 �� 5 ��Ϊ���񣩣�
6 �� 9 ͬ��������Щ����������������ת�Ժ󶼲�������Ч�����֡�

����������һ��������?N, �����?1 ��?N ���ж��ٸ���?X �Ǻ�����

*/


// �ж�һ�����ǲ��Ǻ��� , �ж������ÿ��λ�ǲ���ֻ��1,2,5,6,8,9,0,    �����ٺ�һ��2,5,6,9
bool isGood(int num) {
	int temp = num;
	bool flag = false;
	while(temp!=0) {
		int dis = temp%10;
		if(dis==3||dis==4||dis==7) return false;
		if(dis == 2||dis==5||dis==6||dis==9) flag=true;
		temp/=10;
	}
	if(flag) return true;
	return false;


}


int rotatedDigits(int n) {
	int cnt = 0;
	for(int i =  1; i<=n; i++) {
		if(isGood(i)) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cout<<rotatedDigits(10);
}
