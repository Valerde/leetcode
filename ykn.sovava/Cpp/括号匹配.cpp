#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
	int cnt = 0,ans = 0;
	for(auto& c:s) {
		if(c=='(')cnt++;
		else {
			if(cnt>0) cnt--;
			else ans++;
		}
	}
	return res+cnt;
}
int main() {
}
