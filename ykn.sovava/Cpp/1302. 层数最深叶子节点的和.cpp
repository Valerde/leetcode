/*
����һ�ö������ĸ��ڵ� root �����㷵�� ���������Ҷ�ӽڵ�ĺ� ��

*/

#include<bits/stdc++.h>
using namespace std;
//������ȱ���
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

//������ȱ���
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
