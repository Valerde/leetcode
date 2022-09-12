#include<bits/stdc++.h>
using namespace std;
int player[4];
bool pjdr(int m) {
	if(m%7==0) return true;
	while(m) {
		if(m%10==7)return true;
		m/=10;
	}
	return false;
}
int main() {
	int n;
	scanf("%d",&n);

	for(int i = 0,j=1; i<n; j++) {
		if(pjdr(j)) {
			player[(j-1)%4]++;

		} else {
			i++;
		}
	}
	for(int i=0; i<4; i++) {
		cout<<player[i]<<endl;
	}
}
