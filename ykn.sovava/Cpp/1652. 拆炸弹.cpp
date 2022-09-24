#include<bits/stdc++.h>
using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
	int n = code.size();
	vector<int> v(n,0) ;
	if(k==0) return v;

	for(int i = 0; i<n; i++) {
		if(k>0) {
			for(int j = 1; j<=k; j++)
				v[i] += code[(i+j)%n];
		} else if(k<0) {
			for(int j = -1; j>=k; j--)
				v[i]+= code[(i+j+n)%n];
		}


	}

	return v;
}

int main() {
	vector<int> code {2,4,9,3};

	vector<int> res = decrypt(code,-2);

	for(int i = 0; i<res.size(); i++)
		cout<<res[i]<<" " ;
}
