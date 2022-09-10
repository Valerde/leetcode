#include<bits/stdc++.h>
using namespace std;
const long N = 10005;
int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	int ns[N]={0};
	int t = 0;
	int i;
	for( i= 1; i<=a; i++) {
		scanf("%d",&ns[i]);
		t+=(ns[i]-ns[i-1])*(i-1);
	}
	//cout<<i<<endl;
	t+=(b-ns[i-1])*(i-1);
	cout<<t;
}
