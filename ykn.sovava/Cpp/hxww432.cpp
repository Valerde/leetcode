#include<bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin>>N;
	vector<int> in(N);
	for(int i = 0; i<N; i++) {
		cin>>in[i];
	}

	int cnt = 0;
	vector<int> ma(N);
	ma[N-1] = INT_MAX;
	for(int i = N-2; i>=0; i--) {
		ma[i] = min(ma[i+1],in[i+1]);
		if(in[i]>2*ma[i])cnt++;
	}
	cout<<cnt;
}
