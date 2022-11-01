#include<bits/stdc++.h>
using namespace std;
int magicalString(int n) {
	string s(n,'0');
	s[0] = '1';
	s[1] = '2';
	s[2] = '2';
	int i =2 , j = 3,res = 1;
	while(j<n) {
		int size = s[i]-'0';
		int num = 3-(s[j-1]-'0');
		while(size--&&j<n) {
			s[j] = num+'0';
			if(num == 1) res++;
			j++;
		}
		i++;
	}
	return res;

}
