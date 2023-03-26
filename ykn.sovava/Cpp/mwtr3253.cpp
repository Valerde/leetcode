#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin>>n;
	vector<ll> in(n);
	int q;
	cin>>q;
	vector<int> qs(q);
	for(int i = 0; i<n; i++) {
		cin>>in[i];
	}
	sort(in.begin(),in.end());
	for(int  i = 0; i<q; i++) {
		cin>> qs[i];
	}
	sort(qs.begin(),qs.end());
	int j = 0,res = 0;
	for(int i = 0; i<q; i++) {
		ll temp = qs[i];
		for(; j<n; j++) {
			if(temp-in[j]>0) {
				temp-=in[j];
			} else {
//				res++;
				break;
			}
		}
	}
	cout<<j;
}
