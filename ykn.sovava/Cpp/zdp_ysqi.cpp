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
С��Ҫ��һ�����߶���������Ϸ�����ڶ���Ⱥ��ķ�������������Ե���N��ɽ������i��ɽ������ki ֻ���������У�ÿ������������ֵ���ǲ�ͬ�ġ���С������һ��ɽ��ʱ�������밴�ո�����˳�����δ��ÿֻ������

���ң����ҽ�����������ֵ�ϸ���ڵ�ǰ����������ֵʱ�����ܴ�ܸö�����ÿ��С�����һֻ��������������ֵ���+1��

��֪��С����������ѡ�����ɽ����˳�򣬵��ǽ���ɽ������Ҫ����˳���ܶ��������ʣ�С�����������Ҫ�߱���������ֵ���ſ��Կ�ʼ�ⳡ���߶���������Ϸ��
