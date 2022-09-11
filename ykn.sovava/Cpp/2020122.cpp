#include<bits/stdc++.h>
using namespace std;

bool ms(pair<int,int> p1,pair<int,int> p2) {
	if(p1.first==p2.first)
		return p1.second<p2.second;
	return p1.first<p2.first;
}
int main() {
	int m,a,b;
	scanf("%d",&m);
	vector<pair<int,int>> v;
	pair<int,int> p;
	for(int i = 0; i<m; i++) {
		scanf("%d%d",&a,&b);
		p.first=a;
		p.second=b;
		v.push_back(p);
	}

	sort(v.begin(),v.end(),ms);
	cout<<"----------"<<endl;
	for(auto&& d:v) {
	cout<<d.first<<" "<<d.second<<endl;
	}

	int cs[100005][2]= {0};
	cs[0][0]=0;
	for(int i = 1; i<=m; i++) {
		cs[i][0]=cs[i-1][0]+(v[i-1].second==0);
	}
	cs[m-1][1]=(v[m-1].second==1);
	for(int i=m-2; i>=0; i--) {
		cs[i][1]=cs[i+1][1]+(v[i].second==1);
	}
	cout<<"----------"<<endl;
	for(int i=0; i<m; i++) {
	cout<<cs[i][0]<<" "<<cs[i][1]<<endl;
	}

	int ad=cs[1][0]+cs[1][1],temp=1;
	for(int i = 1; i<m; i++) {
		if(v[i].first==v[i-1].first) continue; 
		if((cs[i][0]+cs[i][1])>=ad) {
			temp=i;
			ad=cs[i][0]+cs[i][1];
		}
	}
	
	//cout<<"------"<<endl;
	cout<<v[temp].first<<endl;


}
