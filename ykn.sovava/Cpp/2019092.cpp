#include<bits/stdc++.h>
using namespace std;

int f1,f2,l1,l2;
int cntdrp=0,tmpcnt=0,cntgrp,m,n;
int tt=0,drp=0,ind=1,indt=-1,total=0,an,sn;
int main() {
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&m);
		ind=0;
		for(int j=0; j<m; j++) {
			if(j==0) {
				scanf("%d",&tt);
			} else {
				scanf("%d",&drp);
				if(drp>0) {
					if(tt>drp) {
						tt=drp;
						ind=1;
						if(i==0) {
							f1=1;
						}
						if(i==1) {
							f2=1;
						}
						if(i==n-2) {
							l2=1;
						}
						if(i==n-1) {
							l1=1;
						}
					}

				} else {
					tt+=drp;
				}
			}

		}
		if(ind==1) {
			tmpcnt++;
			cntdrp++;
		} else {
			tmpcnt=0;
		}
		if(tmpcnt>=3) {
			cntgrp++;
		}
		total+=tt;
	}

	cntgrp+=l2&&l1&&f1;
	cntgrp+=l1&&f1&&f2;
	if(n<3) {
		cntgrp=0;
	}

	cout<<total<<" "<<cntdrp<<" "<<cntgrp<<endl;
}

/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0


5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/
