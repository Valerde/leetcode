/*
3.加工生产调度
某工厂收到了 n 个产品的订单，这 n 个产品分别在 A、B 两个车间加工，并且必须先在 A 车间加工后才可以到 B 车间加工。
某个产品 i 在 A，B 两车间加工的时间分别为Ai,Bi。怎样安排这 n 个产品的加工顺序，才能使总的加工时间最短。
这里所说的加工时间是指：从开始加工第一个产品到最后所有的产品都已在 A，B 两车间加工完毕的时间。
输入：
第一行仅—个数据 n ，表示产品的数量；
接下来 n 个数据是表示这 n 个产品在 A 车间加工各自所要的时间；
最后的 n 个数据是表示这 n 个产品在 B 车间加工各自所要的时间。
输出：
第一行一个数据，表示最少的加工时间；
第二行是一种最小加工时间的加工顺序。
输入样例：
5
3 5 8 7 10
6 2 1 4 9
输出样例：
34
1 5 4 2 3

*/
/*
令a为A中时间，b为B中时间
设  A[]为 a < b 的作业集合，B[] 为 a >= b 的作业集合，将 A[] 的作业按 a 升序排序，
B[] 中的作业按照 b 降序排序，则 A[] 作业接 B[] 构成最优顺序
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
	int tot = 0;//A中顺序执行，A空闲，主要发生在A已经完了，B还在工作，B中空闲主要发生在A中工作，B手头空闲，以及刚开始。
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
			if (temp1 + A[lena].a < tot) {//第一车间加工完第二组第一个了，第二车间还没加工完第一组
				tot = temp1 + A[i].a;
			}
			else if (temp1 + A[lena].a >= tot) {//第一车间还没有加工完第二组第一个，dierchejian 就已经加工完第一组
				temp2= A[0].a+(temp1+A[i].a-tot);//temp2为第二车间AB两组转换中间等待空闲时间
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



