#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin>>str;
	int len = str.size();
	string ans="";
	for(int i = 0; i<len;) {
		int num = 1;
		char c=str[i];
		while(str[i]==str[i+1]) {
			num++;
			i++;
		}
		if(num==1) {
			ans+=c;
		} else {
			ans.push_back('0'+num);
			ans+=c;
		}
		i++;

	}
	cout<<ans;
}

