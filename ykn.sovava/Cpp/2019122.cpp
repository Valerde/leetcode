#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int n;
int trash[1005];
bool findXY(int x,int y) {
	for(int i=0; i<n; i++) {
		if(v[i].first==x&&v[i].second==y)return true;
	}
	return false;
}
bool find(pair<int,int> p) {
	if(findXY(p.first-1,p.second)&&findXY(p.first+1,p.second)
	        &&findXY(p.first,p.second+1)&&findXY(p.first,p.second-1)) {
		return true;
	} else {
		return false;
	}
}
int main() {
	int x,y;
	scanf("%d",&n);
	for(int i = 0; i<n; i++) {
		scanf("%d%d",&x,&y);
		v.push_back({x,y});
	}
	int ans[5]= {0};
	pair<int ,int> p;
	for(auto&& it:v) {
		int count = 0;
		if(find(it)) {
			if(findXY(it.first-1,it.second-1)) count++;
			if(findXY(it.first+1,it.second-1)) count++;
			if(findXY(it.first-1,it.second+1)) count++;
			if(findXY(it.first+1,it.second+1)) count++;
			ans[count]++;
		}

	}



	for(int i = 0; i<5; i++) {
		cout<<ans[i]<<endl;
	}
}

/*
11
9 10
10 10
11 10
12 10
13 10
11 9
11 8
12 9
10 9
10 11
12 11
*/
