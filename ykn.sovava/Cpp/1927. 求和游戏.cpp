#include<bits/stdc++.h>
using namespace std;

bool sumGame(string num) {
	int n =num.size();
	int hn = n/2;

	int lsum = 0,lwen = 0;
	for(int i = 0; i<hn; i++)
		if(num[i]>='0'&&num[i]<='9') {
			lsum+=num[i]-'0';
		} else {
			lwen++;
		}

	int rsum = 0, rwen = 0;
	for(int i = hn; i<n; i++)
		if(num[i]>='0'&&num[i]<='9') {
			rsum+=num[i]-'0';
		} else {
			rwen++;
		}

	int dwen = lwen - rwen;
	int dsum = lsum - rsum;
	if(dsum*2 == -9* dwen) {
		return false;
	}
	return true;

}
