#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<int> in(n);
	vector<int> out(n);
	for(int i = 0; i<n; i++) {
		cin>>in[i];
	}
	for(int i = 0; i<n; i++) {
		cin>>out[i];
	}
	stack<int> stk;
	int j=0;
	for(int i = 0; i<n; i++) {
		while(j<n&&(stk.empty()||stk.top()!=out[i])) {
			stk.push(in[j++]);
		}
		if(j == n&& stk.top()!=out[i]) {
			cout<<" No" <<endl;
			return 0;
		} else {
			stk.pop();
		}
	}
	cout<<"Yes"<<endl;
}
