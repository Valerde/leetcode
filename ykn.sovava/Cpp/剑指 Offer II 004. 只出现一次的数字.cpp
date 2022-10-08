#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
	int res = 0;

	for(int i = 0; i<32; i++) {
		int cnt = 0;
		for(auto&& val:nums) {
			cnt+=(val>>i)&1;
		}
		if(cnt%3) {
			res|=(1<<i);
		}
	}
	return res;
}


int main() {

}
