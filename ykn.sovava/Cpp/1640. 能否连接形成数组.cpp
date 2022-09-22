#include<bits/stdc++.h>
using namespace std;
bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
	bool flag[pieces.size()] = {false};
	int idx = 0;
	for(; idx<arr.size();) {
		bool enter = false;
		for(int j = 0; j<pieces.size(); j++) {
			if(flag[j]==false&&arr[idx]==pieces[j][0]) {
				enter = true;
				flag[j]=true;
				for(int k = 0; k<pieces[j].size(); k++) {
					if(arr[idx]==pieces[j][k]) idx++;
					else {
						enter = false;
						break;
					}
				}
				if(flag[j]=true&&enter = false;) break;
			}
		}
		if(enter==false&&idx!=arr.size()-1) return false;
		if(enter==true&&idx==arr.size()-1)return true;
		//idx++;
	}
}

int main() {
	canFormArray()
}
