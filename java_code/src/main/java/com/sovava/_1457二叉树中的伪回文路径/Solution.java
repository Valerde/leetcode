package com.sovava._1457二叉树中的伪回文路径;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月25日 4:59 PM
 **/
class Solution {
    public int pseudoPalindromicPaths(TreeNode root) {
        int[] cnt = new int[10];
        return dfs(root, cnt);
    }

    public int dfs(TreeNode node, int[] cnt) {
        if (node == null) {
            return 0;
        }
        cnt[node.val]++;
        int res = 0;
        if (node.left == null && node.right == null && ispseudoPalindromic(cnt)) {
            res = 1;
        } else {
            res = dfs(node.left, cnt) + dfs(node.right, cnt);
        }
        cnt[node.val]--;
        return res;
    }

    public boolean ispseudoPalindromic(int[] cnt) {
        int a = 0;
        for (int i = 1; i < 10; i++) {
            if (cnt[i] % 2 != 0) {
                a++;
            }
        }
        return a <= 1;
    }


    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, Solution.TreeNode left, Solution.TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
