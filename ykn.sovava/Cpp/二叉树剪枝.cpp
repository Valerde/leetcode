#include<bits/stdc++.h>
using namespace std;
/*
����������ĸ����?root?����������ÿ������ֵҪô�� 0 ��Ҫô�� 1 ��

�����Ƴ������в����� 1 ��������ԭ��������

�ڵ� node ������Ϊ node ����������� node �ĺ����

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
