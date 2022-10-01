#include<bits/stdc++.h>
using namespace std;
/*
给你二叉树的根结点?root?，此外树的每个结点的值要么是 0 ，要么是 1 。

返回移除了所有不包含 1 的子树的原二叉树。

节点 node 的子树为 node 本身加上所有 node 的后代。

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

TreeNode* pruneTree(TreeNode* root) {
	if(!root) return nullptr;
	root->left = pruneTree(root->left)  ;
	root->right = pruneTree(root->right);
	if(!root->left&& !root->right &&!root->val) return nullptr;
	return root;
}

/**/
