/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include<bits/stdc++.h>
using namespace std;

int maxDepth(Node* root) {
	if(root == nullptr) return 0;
	int maxchilddepth = 0;
	for(auto&& val:root->children) {
		int maxchild = maxDepth(val);
		maxchilddepth = max(maxchild,maxchilddepth);
	}
	return maxchilddepth+1;
}

