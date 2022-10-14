#include<bits/stdc++.h>
using namespace std;
int maxChunksToSorted(vector<int>& arr) {
	int res  = 0, m = -1;
	for(int i = 0; i < arr.size(); i++) {
		m = max(arr[i],m);
		if(m == i) res++;
	}
	return res;
}
int main(){
	 vector<int> arr{1,0,2,3,4};
	cout<<maxChunksToSorted(arr);
}
