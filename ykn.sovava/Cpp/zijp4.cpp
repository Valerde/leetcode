#include<bits/stdc++.h>
using namespace std;
void solve(int &m,vector<set<pair<int,int>>> &v,set<pair<int,int>> &all) {
	int ans = 0,seq = 0;
	for(auto &p:all) {
		seq = 0;
		for(int  i = 0; i<m; i++) {
			if(v[i].count(p)) seq++;
			else {
				ans = max(ans,seq);
				seq = 0;
			}
		}
		ans = max(ans,seq);
	}
	cout<<ans<<endl;
}
int main() {
	int N;
	cin>>N;
	while(N--) {
		int m;
		cin>>m;
		vector<set<pair<int,int>>> v(m);
		set<pair<int,int>> all;
		for(int i = 0; i<m; i++) {
			int c;
			cin>>c;
			for(int j = 0; j<c; i++) {
				int temp1,temp2;
				cin>>temp1>>temp2;
				v[i].insert({temp1,temp2});
				all.insert({temp1,temp2});
			}
		}
		solve(m,v,all);
	}
}
