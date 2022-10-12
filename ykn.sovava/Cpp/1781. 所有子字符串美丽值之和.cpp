#include<bits/stdc++.h>
using namespace std;

int cal(string s) {

	vector<int> cnt(26,0);
	int maxnum = INT_MIN,minnum = INT_MAX;
	for(int k = 0; k<s.size(); k++) {
		cnt[s[k]-'a']++;

	}

	for(auto&& val:cnt) {
		if(maxnum<val)maxnum = val;
		if(minnum>val&&val!=0) minnum = val;
	}



	return (maxnum-minnum);
}

int beautySum(string s) {

	int n = s.size();
	if(n<3)return 0;
	int res = 0;
	for(int i = 0; i< n-1; i++)
		for(int j = i+1; j<n; j++) {
			string a = s.substr(i,j-i+1);

			short cnt[26]= {0};
			int maxnum = INT_MIN,minnum = INT_MAX;
			for(int k = 0; k<s.size(); k++) {
				cnt[s[k]-'a']++;

			}

			for(auto&& val:cnt) {
				if(maxnum<val)maxnum = val;
				if(minnum>val&&val!=0) minnum = val;
			}



			res+= (maxnum-minnum);


		}
	return res;

}


int beautySum(string s) {
	int l=s.size();
	if(l<3)return 0;

	int result=0;
	for(int i=0; i<l; i++) {
		short charcnt[26]= {0};
		int charflag=0;
		for(int j=i; j<l; j++) {
			int index = s[j]-'a';
			charcnt[index]++;
			charflag|=(1<<index);
			short cmin=1000;
			short cmax=-1;
			for(int k=0; k<26; k++) {
				if(charflag&(1<<k)) {
					cmin = min(cmin,charcnt[k]);
					cmax = max(cmax,charcnt[k]);
				}
			}
			result+=cmax-cmin;
		}
	}
	return result;

}

int main() {


	cout<<beautySum("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef");
}
