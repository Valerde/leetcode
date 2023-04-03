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
class Solution {
public:
    bool digv(TreeNode* left,TreeNode* right){
        if(left==nullptr&&right==nullptr) return true;
        else if((left==nullptr&&right!=nullptr)||(left!=nullptr&&right==nullptr)) return false;
        else if(left->val!=right->val) return false;
        else return digv(left->left,right->right)&&digv(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return digv(root->left,root->right);
    }
};
