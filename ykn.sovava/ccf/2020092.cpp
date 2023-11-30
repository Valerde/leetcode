#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,k,t,xl,yd,xr,yu;
	scanf("%d%d%d%d%d%d%d",&n,&k,&t,&xl,&yd,&xr,&yu);
	int cj[21],cd[21];
	int ps[10005][2],jd=0;
	for(int i=0; i<n; i++) {
		jd=0;
		for(int j=0; j<t; j++) {
			scanf("%d%d",&ps[j][0],&ps[j][1]);

			if(ps[j][0]>=xl&&ps[j][0]<=xr&&ps[j][1]>=yd&&ps[j][1]<=yu) {
				cj[i]=1;
				jd++;
				if(jd>=k) {
					cd[i]=1;
				}
			} else {
				jd=0;
			}
		}
	}
	int a=0,b=0;
	for(int i = 0; i<n; i++) {
		if(cj[i]) a++;
		if(cd[i]) b++;
	}
	cout<<a<<"\n"<<b;
}
