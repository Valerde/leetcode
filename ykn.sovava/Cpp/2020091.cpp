#include<bits/stdc++.h>
using namespace std;

bool ms(pair<int,int> p1,pair<int,int> p2) {
	if(p1.second==p2.second)
		return p1.first<p2.first;
	return p1.second<p2.second;
}
int main() {
	int n,X,Y;
	scanf("%d%d%d",&n,&X,&Y);
	int ps[1005][2];
	vector<pair<int,int>> v;
	for(int i=0; i<n; i++) {
		scanf("%d%d",&ps[i][0],&ps[i][1]);
		int d2 = (X-ps[i][0])*(X-ps[i][0])+(Y-ps[i][1])*(Y-ps[i][1]);
		v.push_back(make_pair(i+1,d2));
	}

	sort(v.begin(),v.end(),ms);

//	for(auto&& s:v) {
//		cout<<s.first<<" "<<s.second<<endl;
//	}
	
	for(int i=0;i<3;i++){
		cout<<v[i].first<<endl;
	}

}
