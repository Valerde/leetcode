#include<bits/stdc++.h>
using namespace std;
int a[1005][2],b[1005][2],x,y,Alen=0,Blen=0;
char c;
void pjdr(int si,int si1,int si2) {
	int afu = (si+si1*a[0][0]+si2*a[0][1])>0?1:-1;
	for(int i=1; i<Alen; i++) {
		if((si+si1*a[i][0]+si2*a[i][1])*afu<0) {
			cout<<"No"<<endl;
			return;
		}
	}
	int bfu = (si+si1*b[0][0]+si2*b[0][1])>0?1:-1;
	if (bfu==afu) {
		cout<<"No"<<endl;
		return ;
	}
	for(int i=1; i<Blen; i++) {
		if((si+si1*b[i][0]+si2*b[i][1])*bfu<0) {
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
	return ;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);

	char no;
	for(int i = 0; i<n; i++) {
		scanf("%d%d %c",&x,&y,&c);
		if(c=='A') {
			a[Alen][0]=x;
			a[Alen++][1]=y;
		} else {
			b[Blen][0]=x;
			b[Blen++][1]=y;
		}
	}
	int si,si1,si2;
	for(int i = 0; i<m; i++) {
		scanf("%d%d%d",&si,&si1,&si2);
		pjdr(si,si1,si2);
	}

}

/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1
*/
