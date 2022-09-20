#include<bits/stdc++.h>
using namespace std;
int nthUglyNumber1(int n) {
	int n1=0,n2=0,n3=0;
	int a=0,b=0,c=0;
	int dp[n];
	dp[0]=1;
	for(int i = 1; i<n; i++) {
		n1=dp[a]*2;
		n2=dp[b]*3;
		n3=dp[c]*5;
		int m = min(min(n1,n2),n3);
		if(m==n1) a++;
		if(m==n2) b++;
		if(m==n3)c++;
		dp[i]=m;
	}
	return dp[n-1];
}


int nthUglyNumber(int n) {
	vector<int> factors {2,3,5};
	unordered_set<long> s;
	s.insert(1L);
	priority_queue<long,vector<long>,greater<long>> heap;
	heap.push(1L);
	int ugly=0;
	for(int i = 0; i<n; i++) {
		long ucrr = heap.top();
		heap.pop();
		ugly = (int)ucrr;
		for(auto a:factors) {
			long next = ucrr*a;
			if(!s.count(next)) {
				s.insert(next);
				heap.push(next);
			}
		}
	}
	return ugly;
}
int main() {
	cout<<nthUglyNumber1(500);

}
