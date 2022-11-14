#include<bits/stdc++.h>
using namespace std;
long long appealSum(string s) {
	long long res = 0;
	vector<int> lastIndex(26,-1);
	for(int i = 0,sum = 0;i<s.size();i++){
		int j = lastIndex[s[i]-'a'];
		sum+=i-j;
		res+=sum;
		lastIndex[s[i]-'a'] = i;
	}
	return res;
	
	
}



class Solution {
public:
    long long appealSum(string nums) {
        vector<int> lastpos(26, -1);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums.size() - i) * (i - lastpos[nums[i] - 'a']);
            lastpos[nums[i] - 'a'] = i;
        }
        return sum;
    }
};
