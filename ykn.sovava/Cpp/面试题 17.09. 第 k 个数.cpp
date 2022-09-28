#include<bits/stdc++.h>
using namespace std;
int getKthMagicNumber(int k) {
	vector<int> v {1};
	int a = 3 , b = 5 , c = 7;
	int cnt = 1;
	int aa = 0,bb = 0,cc = 0;
	while(cnt<=k) {
		int _temp = min(a*v[aa],min(b*v[bb],c*v[cc]));
		if(_temp == a*v[aa]) aa++;
		if(_temp == b*v[bb]) bb++;
		if(_temp == c*v[cc]) cc++;
		v.push_back(_temp);
		cnt++;
	}
	
	return v[k-1];
}


int main() {
	cout<<getKthMagicNumber(7);
}
