/*
3�����ܻ�õ����ϲ����
����������
��һ������Ϊ����ʹ�õ�Ǯ���ܶ� X ����Ʒ��������� N����������ͨ���ո����
�ڶ��п�ʼ��ÿ��Ϊһ����һ����Ʒ����������Ϣ�ǣ���Ʒ���� P������Ʒ���� amt������Ʒϲ���� fav
ʾ����
���룺
10 4
2 2 2
5 2 2
4 1 3
9 1 3

�����
7 2
1 2
3 1
���ͣ��� 10 ��Ǯ������ϲ������7������2����Ʒ��
���� ��һ����Ʒ2 �����õ���ϲ������ 4���ٹ����������Ʒ 1 �����õ���ϲ������ 3��
*/

;
/*
* ��������ʵ���������������������ڹ涨�Ľ���ڣ��涨����Ʒ�����ڴﵽ����ϲ���ȡ�
* dp[money]��ʾ��money���Ǯ��õ����ϲ���ȡ�
* mem[j]��ʾ�ڻ���Ϊj��Ǯ���������������Ʒ��ź͸�����
* 

*/

#include<iostream>
#include<algorithm>
using namespace std;
int money;
int n;
struct Data {
	int p;
	int amt;
	int fav;
};
Data dat[20];
int dp[50] = { 0 };
struct Mem {
	int num;
	int amt;
};
Mem mem[20];
void setmy() {
	cin >> money >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dat[i].p >> dat[i].amt >> dat[i].fav;
	}

}

int main(void) {
	setmy();
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = money; j > dat[i].p; j--) {
			for (int k = 1; k <= dat[i].amt && money - k * dat[i].p >= 0; k++) {
				temp = dp[j];
				dp[j] = max(dp[j], dp[j - k * dat[i].p] + k * dat[i].fav);
				if (dp[j] != temp) {
					mem[j].amt = k;
					mem[j].num = i;
				}
			}
		}
	}
	temp = 0;
	printf("--------------\n");
	for (int i = 0; i <= money; i++) {
		if (mem[i].num == temp) {
			continue;
		}
		printf("%d  %d\n", mem[i].num,mem[i].amt);
		temp = mem[i].num;
	}
	cout << dp[money];
	return 0;
}



