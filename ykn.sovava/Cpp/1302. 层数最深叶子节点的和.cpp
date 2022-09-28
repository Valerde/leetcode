/*
给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。

*/

#include<bits/stdc++.h>
using namespace std;
//广度优先遍历
int _deepestLeavesSum(TreeNode* root) {


	int deep = 1;
	int sum = 0;
	queue<TreeNode*> que;
	que.emplace(root);
	while(queue.size()!=0) {
		sum=0;
		int size = queue.size();
		for(int i = 0; i<size; i++) {
			TreeNode* temp = que.front();
			que.pop();
			if(temp->left!=nullptr) que.emplace(temp->left);
			if(temp->right!=nullptr) que.emplace(temp->right);
			sum+=temp->val;
		}
	}
	return sum;

}

//深度优先遍历
int maxlevel = -1;
int sum = 0;
void dfs(TreeNode* node , int leval) {
	if(node ==nullptr) return ;
	if(leval>maxleval) {
		maxlevel = level;
		sum = node->val;
	} else if(level == maxlevel) sum+=node->val;
	dfs(node->left,level+1) ;
	dfs(node->right,level+1);
}
int deepestLeavesSum(TreeNode* root) {
	dfs(root,0);
	return sum;
}


int main() {}
