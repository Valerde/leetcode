/*
�ַ�����ת�����������ַ���s1��s2�����д������s2�Ƿ�Ϊs1��ת���ɣ����磬waterbottle��erbottlewat��ת����ַ�������


*/

#include<bits/stdc++.h>
using namespace std;
bool __isFlipedString(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	if(len1!=len2)return false;
	if(len1 == 0) return true;
	for(int i = 0; i<len1; i++) {
		bool flag = true;
		for(int j = 0; j<len2; j++) {
			if(s1[j]!=s2[(i+j)%len1]) {
				flag = false;
				break;
			}
		}
		if(flag)return true;
	}
	return false;
}
//(s1 + s1)
bool _isFlipedString(string s1, string s2) {
	return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;
}

bool isFlipedString(string s1, string s2) {
	
}
int main() {
	cout<<isFlipedString("qwer","erqw");
}

