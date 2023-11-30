#include<bits/stdc++.h>
using namespace std;
int nn;
int res,n[4];
char c[3];
int cal(int x,char c,int y) {
	if(c=='+') {
		return x+y;
	} else if(c=='-') {
		return x-y;
	} else if(c=='/') {
		return x/y;
	} else {
		return x*y;
	}
}

int cal1() {
	for(int i=0; i<3; i++) {
		if(c[i]!='+'&&c[i]!='-') {
			n[i+1]=cal(n[i],c[i],n[i+1]);
			n[i]=0;
			c[i]=i>0?c[i-1]:'+';
		}
	}
	int temp = n[0];
	for(int i = 0; i<3; i++) {
		temp = cal(temp,c[i],n[i+1]);
	}
	return temp;
}
int main() {

	scanf("%d",&nn);
	for(int i = 0; i<nn; i++) {
		scanf("%d%c%d%c%d%c%d",&n[0],&c[0],&n[1],&c[1],&n[2],&c[2],&n[3]);


		if(cal1()==24) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}

	}
}

/*
4
9+3+4*3
5+4*5*5
7-9-9+8
5*6/5*4
*/
