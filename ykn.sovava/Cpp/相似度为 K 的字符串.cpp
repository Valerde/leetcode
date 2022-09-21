#include<bits/stdc++.h>
using namespace std;
//������� , ���� , ��֦ 
void swap(string& s,int i,int j) {
	char a = s[i];
	s[i] = s[j];
	s[j] =a;
}
void backtrancking(string& s1,string& s2,int start,int current,int& depth) {
	if(current>=depth) return ;
	if(start==s1.size()-1) {
		depth = min(current,depth);
		return;
	}


	for(int i = start; i<s1.size(); i++) {
		if(s1[i]!=s2[i]) {
			for(int j=i+1; j<s1.size(); j++) {
				if(s2[j]==s1[i]&&s2[j]!=s1[j]) {
					swap(s2,i,j);
					backtrancking(s1,s2,start+1,current+1,depth);
					swap(s2,i,j);
				}
			}
			return ;
		}
	}
	depth = min(current,depth);
}
int kSimilarity(string s1, string s2) {
	int cnt=0;
	for(int i=0; i<s1.size(); i++) {
		if(s1[i]!=s2[i]) {
			for(int j = i+1; j<s2.size(); j++) {
				if(s1[i]==s2[j]&&s1[j]==s2[i]) { // ̰��Ԥ�ȴ��� , ���һ�ν����������λ�õĶ��� , ��ôһ������õ��㷨 
					swap(s2,i,j);
					cnt++;
					break;
				}
			}
		}

	}
	int depth = INT_MAX;
	backtrancking(s1,s2,0,0,depth);
	return depth+cnt;
}
int main() {
	string s1 = "abc";
	string s2 = "cab";
	int k = kSimilarity(s1,s2);
	cout<<k;
}

