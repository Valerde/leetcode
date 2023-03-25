#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n,k;
	cin>>n>>k;

	vector<int> in(n);
	for(int i = 0; i<n; i++) {
		cin>>in[i];
	}
	int res =INT_MAX;
	sort(in.begin(),in.end());
	vector<int> temp(n,0);
	for(int i = 0; i<k; i++) {
		int mi=in[n-1];
		int ma=in[0];
		for(int j = 0; j<n; j++) {

			if(j<i) {
				temp[j]=in[j]*2;
			} else if(j>=i&&j<n-(k-i)) {
				temp[j]=in[j];
			} else {
				temp[j]=in[j]/2;
			}
		}
		for(int l=0; l<n; l++) {
			mi=min(temp[l],mi);
			ma=max(temp[l],ma);
		}
		res=min(res,ma-mi);
	}
	cout<<res;
}
