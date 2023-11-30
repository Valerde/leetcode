#include<bits/stdc++.h>
using namespace std;
int main() {
	int N = 0;
	vector<pair<int,int>> v ;
	int m = 0;
	cin>>N;
	if(N ==0) {
		cout<<0;
		return 0;
	}

	for(int i = 0; i<N; i++) {
		int tmp = 0, max = 0,idx = 0;
		cin>>m;
		for(int j = 0; j<m; j++) {
			cin>>tmp;
			if(max<tmp-j) {
				max = tmp-j;
				idx = j;
			}
		}
		max = max+1;
		v.push_back({max,max+m});
	}

	sort(v.begin(),v.end(),
	[](const pair<int, int>& a, const pair<int, int>& b) {
		if(a.first < b.first) {
			return true;
		} else if(a.first == b.first) {
			return a.second>b.second;
		} else {
			return false;
		}
	});

	for(int i = 0; i<N; i++) {
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}

	for(int i = N-1; i>0; i--) {
		if(v[i].first>v[i-1].second) {
			cout<<v[i].first<<endl;
			return 0;
		}
	}
	cout<<v[0].first<<endl;
	return 0;
}



//
小花要玩一场勇者斗恶龙的游戏。由于恶龙群体的飞速扩大，她所面对的是N个山洞，第i个山洞里有ki 只恶龙。其中，每个恶龙的生命值都是不同的。当小花进入一个山洞时，她必须按照给定的顺序，依次打败每只恶龙。

并且，当且仅当她的勇气值严格大于当前恶龙的生命值时，才能打败该恶龙。每当小花打败一只恶龙，她的勇气值则会+1。

已知，小花可以任意选择进入山洞的顺序，但是进入山洞后需要按照顺序打败恶龙。请问，小花最初最少需要具备多少勇气值，才可以开始这场勇者斗恶龙的游戏？
