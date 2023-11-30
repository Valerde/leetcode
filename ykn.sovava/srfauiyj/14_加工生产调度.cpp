/*
3.�ӹ���������
ĳ�����յ��� n ����Ʒ�Ķ������� n ����Ʒ�ֱ��� A��B ��������ӹ������ұ������� A ����ӹ���ſ��Ե� B ����ӹ���
ĳ����Ʒ i �� A��B ������ӹ���ʱ��ֱ�ΪAi,Bi������������ n ����Ʒ�ļӹ�˳�򣬲���ʹ�ܵļӹ�ʱ����̡�
������˵�ļӹ�ʱ����ָ���ӿ�ʼ�ӹ���һ����Ʒ��������еĲ�Ʒ������ A��B ������ӹ���ϵ�ʱ�䡣
���룺
��һ�н��������� n ����ʾ��Ʒ��������
������ n �������Ǳ�ʾ�� n ����Ʒ�� A ����ӹ�������Ҫ��ʱ�䣻
���� n �������Ǳ�ʾ�� n ����Ʒ�� B ����ӹ�������Ҫ��ʱ�䡣
�����
��һ��һ�����ݣ���ʾ���ٵļӹ�ʱ�䣻
�ڶ�����һ����С�ӹ�ʱ��ļӹ�˳��
����������
5
3 5 8 7 10
6 2 1 4 9
���������
34
1 5 4 2 3

*/
/*
��aΪA��ʱ�䣬bΪB��ʱ��
��  A[]Ϊ a < b ����ҵ���ϣ�B[] Ϊ a >= b ����ҵ���ϣ��� A[] ����ҵ�� a ��������
B[] �е���ҵ���� b ���������� A[] ��ҵ�� B[] ��������˳��
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
struct Data {
	int a;
	int b;
	int num;
};

Data dat[20];
Data A[20], B[20];

bool cmp1(Data x, Data y) {
	return x.a < y.a;
}
bool cmp2(Data x, Data y) {
	return x.b > y.b;
}
void cal(int lena,int lenb) {
	int tot = 0;//A��˳��ִ�У�A���У���Ҫ������A�Ѿ����ˣ�B���ڹ�����B�п�����Ҫ������A�й�����B��ͷ���У��Լ��տ�ʼ��
	int temp1 = 0, temp2 = 0,temp3=0;
	tot += A[0].a;//
	temp3 += A[0].a;
	//temp1 += tot;
	for (int i = 0; i < lena + lenb; i++) {
		if (i < lena) {
			tot += A[i].b;
			temp1 += A[i].a;
			temp3 += A[i].b;
		}
		else if (i == lena) {
			//tot += A[i].b;
			temp3 += A[i].b;
			if (temp1 + A[lena].a < tot) {//��һ����ӹ���ڶ����һ���ˣ��ڶ����仹û�ӹ����һ��
				tot = temp1 + A[i].a;
			}
			else if (temp1 + A[lena].a >= tot) {//��һ���仹û�мӹ���ڶ����һ����dierchejian ���Ѿ��ӹ����һ��
				temp2= A[0].a+(temp1+A[i].a-tot);//temp2Ϊ�ڶ�����AB����ת���м�ȴ�����ʱ��
				tot = temp1 + A[i].a;
			}
			temp3 += temp2;
		}
		else {
			tot += A[i].a;
			temp3 += A[i].b;
		}
		
	}
	if (temp3 < tot) {
		tot += A[lena + lenb - 1].b;
	}
	else {
		tot = temp3 + A[lena + lenb - 1].b;
	}
	cout << tot << endl;
	//cout << "temp2=" << temp2 << endl;
	for (int i = 0; i < lena + lenb; i++) {
		cout << A[i].num << " ";
	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dat[i].a;
		dat[i].num = i + 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> dat[i].b;
	}
	
	int j = 0, k = 0;
	for (int i = 0; i < n; i++) {
		if (dat[i].a < dat[i].b) {
			A[j++]=dat[i];
		}
		else {
			B[k++]=dat[i];
		}
	}
	int lena=j, lenb=k;

	sort(A, A + lena, cmp1);
	sort(B, B + lenb, cmp2);
	for (int i = 0; i < lenb; i++) {
		A[lena + i] = B[i];
	}
	cal(lena,lenb);
	return 0;
}



