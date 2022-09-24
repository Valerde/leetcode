#include<bits/stdc++.h>
using namespace std;
double mmypow(double x, int n) {
	if(n==1) return x;

	double _temp =	mmypow(x,n/2);
	if(n%2==1) {
		return x*_temp*_temp;
	} else {
		return _temp*_temp;
	}


}

double myPow(double x, int n) {
	if(n==0)return 1;

	if(x==1)return 1;
	double result = 1;

	bool flag = false;
	if(n==-2147483648) {
		flag=true;
		n++;
	}


	int vgfu = n>=0?1:-1;
	n=n>0?n:-n;
	result = mmypow(x,n);


	if(vgfu==1)
		return result;
	if(flag)
		return 1/result/x;
	return 1/result;

}

//¹Ù·½ 
double quickMul(double x, long long N) {
	if (N == 0) {
		return 1.0;
	}
	double y = quickMul(x, N / 2);
	return N % 2 == 0 ? y * y : y * y * x;
}

double myPow1(double x, int n) {
	long long N = n;
	return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
}



int main() {

	cout<<myPow(2,-2147483648);

}


