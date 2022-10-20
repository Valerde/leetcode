#include<bits/stdc++.h>
using namespace std;
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
		int cnt[2] = {0,0};
		for(auto&& val : students) cnt[val]++;
		for(auto&& val : sandwiches) if(cnt[val--] == 0) return vnt[val ^ 1];
    } 
