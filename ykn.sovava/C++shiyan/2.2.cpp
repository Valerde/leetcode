#include<iostream>
#include  <malloc.h>
#include <vector>

int diguicount = 0;
using namespace std;
void niubi();
int digui(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return (digui(n - 1) + digui(n - 2));
	}
}
int main(void) {
	int n;
	cin >> n;
	unsigned long long* p;
	p=(unsigned long long*)calloc(n,sizeof(long long *));
	if (p == NULL)   //�����ж��Ƿ�Ϊ�գ����򽫳��֣�����NULLָ������á�����
		return 0;
	*(p+0) = 0;
	*(p+1) = 1;
	long long i;
	unsigned long long count = 1;
	for (i = 2; i < n; i++) {
		*(p + i) = *(p + i - 1) + *(p + i - 2);
		count += *(p + i);
	}
	cout << "p[n]=" << *(p + n-1) << endl;
	cout << count << endl;
	cout << "----���ٿռ�-------------" << endl;
	niubi();
	cout << "-------vector������----------"<<endl;
	cout << digui(n-1) << endl;
	cout << "----------�ݹ鷨------------"<<endl;
	return 0;
}
void niubi(void) {
	vector<long long>a;
	a.push_back(0);
	a.push_back(1);
	long long n1,i,total=1;
	cout << "enter" << endl;
	cin >> n1;
	for (i = 2; i < n1; i++) {
		a.push_back(a[i - 2] + a[i - 1]);
		total += a[i];
	}
	vector<long long>::iterator it;
	it = a.end();
	it--;
	cout << *it << ",total = " << total << endl;
}