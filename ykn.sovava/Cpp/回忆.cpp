#include<bits/stdc++.h>
using namespace std;
//int main() {
//	vector<<vector<int> > dp(n,vector<int>(2));
//}
bool canCross1(vector<int>& stones) {
	int n = stones.size();
	vector<vector<bool>> dp(n,vector<bool>(2,false));
	dp[1][1] = 1;
	for(int i = 2; i<n; i++) {
		for(int j = 1; j<i; j++) {
			int k = stones[i]-stones[j];
			if(k<=j+1) {
				dp[i][k] = dp[j][k-1]||dp[j][k]||dp[j][k+1];
			}
		}
	}
	for( int i = 0; i<n; i++) {
		if(dp[n-1][i]) return true;
	}
	return false;
}

vector<unordered_map<int,int>> rec;
bool dfs(vector<int>& stones,int i,int lastDis) {
	if(i == stones.size()-1) return true;
		if(rec[i].count(lastDis)) return rec[i][lastDis];
	for(int curDis = lastDis-1; curDis<lastDis+2; curDis++) {
		if(curDis>0) {
			int j = lower_bound(stones.begin(),stones.end(),curDis+stones[i])-stones.begin();
			if(j!=stones.size()&& stones[j] == curDis+ stones[i]&& dfs(stones,j,curDis)) {
				return rec[i][lastDis] = true;
			}
		}
	}
	return rec[i][lastDis]=false;
}
bool canCross(vector<int> & stones) {
	int n = stones.size();
	rec.resize(n);
	return dfs(stones,0,0);
}

int cmp(vector<int> a,vector<int> b){
			if(a[0]==b[0])return a[1]>b[1];
		return a[0]<b[0];}

int main() {
//	vector<int> stone {0,7,5,3,2,2,6,7,8,8,5};(4,vector<int>(2,0))(4,vector<int>(2,0))
vector<vector<int>> dp  {
	{2,1},
	{6,2},
	{6,4},
	{1,4}};
	
	sort(dp.begin(),dp.end(),cmp);
//	sort(dp.begin(),dp.end(),[](vector<int>& a,vector<int> & b){
//		if(a[0]==b[0])return a[1]>b[1];
//		return a[0]<b[0];
//	});
	
//	sort(stone.begin(),stone.begin()+5);
	for(int i = 0;i<4;i++){
		cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
}


vector<int> restoreArray(vector<vector<int>>& adjacentPairrs){
	unordered_map<int,vector<int>> mp;
	for(auto &&val: adjacentPairrs){
		mp[val[0]].push_back(val[1]);
		mp[val[1]].push_back(val[0]);
	}
	int n = adjacentPairrs.size()+1;
	int e = 0;
	for(auto&& [key,vec]:mp){
		if(vec.size() == 1){
			e = key;
			break;
		}
	}
	vector<int> n(n,0);
	res[0] = e;
	res[1] = mp[e][0];
	for(int i = 2;i<n;i++){
		auto& ret = mp[res[i-1]];
		res[i] = res[i-2] == ret[0]? ret[1]:ret[0];
	}
	return res;
}
