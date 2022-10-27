#incldue<bits/stdc++.h>
using namespace std;
int arraySign(vector<int>& nums) {
	int count  = 0;
	for(auto && val : nums) {
		if(val<0)count++;
		else if (val == 0)return 0;
	}
	if(count%2 == 0) return 1;
	return -1;
}
