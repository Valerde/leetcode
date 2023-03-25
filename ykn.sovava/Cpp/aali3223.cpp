#include<bits/stdc++.h>
using namespace std;
int len(int num) {
	int res = 1;
	while(num/2) {
		num/=2;
		res++;
	}
	return res;
}

void check(set<int> &s,int node) {
	int temp = node;
	while(temp!=0) {
		if(s.find(temp)!=s.end()) return ;

		temp/=2;
	}

	s.insert(node);

	for(auto it=upper_bound(s.begin(),s.end(),node); it!=s.end(); it++) {
		if(*it!=node) {
			int n = *it;
			while(n>node) {
				n/=2;
			}
			if(n==node) s.erase(*it);

		}

	}
}
int main() {
	int n = 0, q = 0;
	set<int> s;
	cin>> n >> q;
	for(int i = 0; i<q; i++) {
		int in;
		cin>> in;
		check(s,in);
		int res = 0;
		for(auto it:s) {
			res+=pow(2,n-len(it)+1)-1;
		}
		cout<<res<<endl;
	}
}


