#include<bits/stdc++.h>
using namespace std;

int n,m,k;
const int N = 200010;
int ns[N]= {0};
int main() {
	scanf("%d%d%d",&n,&m,&k);
	int temp1,temp2;
	for(int i = 0 ; i < n ; i++) {
		scanf("%d%d",&temp1,&temp2);
		int l = max(0,temp1-k-temp2+1);
		l = min(l,200000);
		int r = max(0,temp1-k);
		r = min(r,200000);
		ns[l]+=1;
		ns[r+1]-=1;
	}
	for(int i = 1 ; i < 200001 ; i++) {
		ns[i]+=ns[i-1];
	}
	int q=0;
	for(int i = 0 ; i < m ; i++) {
		scanf("%d",&q);
		cout<<ns[q]<<endl;
	}
}
