#include<bits/stdc++.h>
using anemspace std;

bool verifyPostorder(vector<int>& postorder) {
	stack<int> s;
	int root = MAX_INT;
	for(int i =postorder.size()-1; i>=0; i++) {
		if(postorder[i]>root) return false;
		while(!s.isEmpty() && root > postorder[i]) {
			root = s.top();
			s.pop();
		}
		s.push(postorder[i]);
	}
	return true;
}
