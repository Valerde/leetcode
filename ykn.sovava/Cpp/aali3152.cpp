#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<int,int> m;
	for(int i = 0;i<n;i++){
		int temp=0;
		cin>>temp;
		m[temp]++;
	}
	vector<int> points;
	for(auto it=m.begin();it!=m.end();it++){
		points.push_back(it->first);
	}
	int len = points.size();
	int res=0;
	for(int i = 0;i<len-1;i++){
		if(points[i+1]==points[i]+1){
			int low=m[points[i]];
			int high=m[points[i+1]];
			res+=low*(low-1)*high/2;
			res+=high*(high-1)*low/2;
		}
	}
	cout<<res;
}
