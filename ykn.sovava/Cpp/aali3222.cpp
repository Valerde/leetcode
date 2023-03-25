#include<bits/stdc++.h>
using namespace std;
int main() {
	int n = 0;
	string s;
	cin>>s;
	vector<int> zeros;
	for(int i = 0; i<s.size(); i++) {
		if(s[i] == '0') {
			zeros.push_back(i);
		}
	}
	n = zeros.size();
	int sum=0;
	for(int i=0; i< n-1; i+=2) {
		sum += zeros[i+1]-zeros[i];
	}
	if(n%2 == 0) {
		cout<<sum<<endl;
	} else {
		if(n==1) {
			cout<<0<<endl;
			return 0;
		}
		int res = sum;
		int temp = 0;
		for(int i = n-1; i>=0; i-=2) {
			if(sum+temp<res) {
				res=sum+temp;
			}
			if(i>0) {
				sum-=zeros[i-1] - zeros[i-2];
				temp += zeros[i] - zeros[i-1];
			}
		}
		cout<<res<<endl;
	}
}
