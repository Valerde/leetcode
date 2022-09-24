#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	if(root == nullptr) return nullptr;
	
	if(p->val>=root->val) return inorderSuccessor(root->right,p);
	TreeNode * ans = inorderSuccessor(root->left,p);
	return ans == nullptr? root:ans;


}


int main() {

}
