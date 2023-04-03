#include<bits/stdc++.h> 
using namespace std;
vector<vector<int> > res;
vector<int> temp;
void dfs(int cur,vector<int> &nums){
	if(cur == nums.size()){
		res.push_back(temp);
		return;
	}
	temp.push_back(nums[cur]);
	dfs(cur+1,nums);
	temp.pop_back();
	dfs(cnt+1,nums);
}
int main(){
	
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i = 0; i<n;i++){
		cin>>vec[i];
	}
	dfs(0,vec);
	return 0;
}
