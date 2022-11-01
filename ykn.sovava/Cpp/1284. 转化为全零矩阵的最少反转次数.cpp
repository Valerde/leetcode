#include<bits/stdc++.h>
using namespace std;

int dirs[6] = {0,0,1,0,-1,0};
int m = 0,n = 0;
int encode(vector<vector<int>>& mat) {
	int res = 0;
	for(int i = 0; i<mat.size(); i++) {
		for(int j= 0; j<mat[0].size(); j++) {
			res=res*2+mat[i][j];
		}
	}
	return res;
}

vector<vector<int>> decode(int num) {
	vector<vector<int>> res(n,vector<int>(m));
	for(int i = n-1; i>=0; i--) {
		for(int j = m-1; j>=0; j--) {
			res[i][j] = num&1;
			num=num>>1;
		}
	}
	return res;
}

void convert(vector<vector<int>>& mat,int i0,int j0) {
	for(int k = 0; k<5; k++) {
		int i1= i0+dirs[k],j1 = j0+dirs[k+1];
		if(i1>=0&&i1<n&&j1>=0&&j1<m) {
			mat[i1][j1] ^= 1;
		}
	}
}


int minFlips(vector<vector<int>>& mat) {
	n = mat.size();
	m = mat[0].size();

	int x = encode(mat),step = 0;
	if(x==0) return 0;

	unordered_set<int> s;
	queue<int> q;
	s.insert(x);
	q.push(x);

	while(!q.empty()) {
		step++;
		int size = q.size();
		for(int l = 0; l<size; l++) {
			vector<vector<int>> status = decode(q.front());
			q.pop();
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
					convert(status,i,j);
					int cur = encode(status);
					if(cur == 0) return step;
					if(!s.count(cur)) {
						s.insert(cur);
						q.push(cur);
					}
					convert(status,i,j);


				}
			}
		}
	}
	return -1;
}
