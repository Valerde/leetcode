#include<bits/stdc++.h>
using namespace std;
int res = 0;
int height(vector<pair<int,int>> points,int root) {
	if(root == -1) return 0;
	return max(height(points,points[root].first),height(points,points[root].second))+1;
}
bool fulltree(vector<pair<int,int> > points,int root) {
	if(root==-1) return true;
	bool l = fulltree(points,points[root].first);
	bool r = fulltree(points,points[root].second);
	if(l&&r&&(height(points,points[root].first) == height(points,points[root].second))) {
		res++;
		return true;
	} else {
		return false;
	}
}


int main() {
	int n;
	cin>>n;

	vector<pair<int,int>> points(n+1);
	vector<int> indegree(n+1,0);
	for(int i = 1; i<=n; i++) {
		int q,p;
		cin>>q>>p;
		points[i].first=q;
		points[i].second=p;
		if(q!=-1) {
			indegree[q]++;
		}
		if(p!=-1) {
			indegree[p]++;
		}
	}
		int root = 1;
		for(int  i =1; i<=n; i++) {
			if(indegree[i]==0) {
				root=i;
				break;
			}
		}
		fulltree(points,root);
		cout<<res;

}
