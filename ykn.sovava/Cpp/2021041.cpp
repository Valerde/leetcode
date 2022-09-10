#include<bits/stdc++.h>
using namespace std;
int ns[257];
int n,m,L;
int main() {
	cin>>n>>m>>L;
	int t;
	for(int i = 0;i<n*m;i++){
		scanf("%d" ,&t);
		ns[t]++;
	} 
	for(int i = 0;i<L;i++){
		printf("%d ",ns[i]);
	}
}
