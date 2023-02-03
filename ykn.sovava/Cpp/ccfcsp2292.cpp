#include<bits/stdc++.h>
using namespace std;

template <typename Tp>
void read(Tp &x) {
	x = 0; int fh = 1; char ch = 1;
	while(ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if(ch == '-') fh = -1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= fh;
}

const int maxn = 30 + 7;

int n, lim, S;
int a[maxn];
bool dp[500000];

void Init(void) {
	read(n); read(lim);
	for(int i = 1; i <= n; i++) {
		read(a[i]); S += a[i];
	}
	cout<<dp[2]<<endl;
	
}

void Work(void) {
	dp[0] = true;
	for(int i = 1; i <= n; i++) {
		for(int j = S; j >= a[i]; j--) {
			dp[j] |= dp[j - a[i]];
		}
	}
	for(int i = lim; i <= S; i++) {
		if(dp[i]) {
			printf("%d\n", i); return ;
		}
	}
}

signed main(void) {
	Init();
	Work();
//	system("pause");
	return 0;
}
