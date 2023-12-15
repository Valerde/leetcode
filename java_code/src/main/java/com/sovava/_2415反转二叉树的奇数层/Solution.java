package com.sovava._2415反转二叉树的奇数层;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月15日 11:58
 **/
public class Solution {


    public TreeNode reverseOddLevels(TreeNode root) {

//        dfs(root.left, root.right, true);
//        return root;
        return bfs(root);
    }

    TreeNode bfs(TreeNode root) {
        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        boolean isOdd = false;
        while (!q.isEmpty()) {
            List<TreeNode> lst = new ArrayList<>();

            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode node = q.poll();
                if (isOdd) {
                    lst.add(node);
                }
                if (node.left != null) {

                    q.offer(node.left);
                    q.offer(node.right);

                }
            }
            if (isOdd) {
                for (int l = 0, r = sz - 1; l < r; l++, r--) {
                    int tmp = lst.get(l).val;
                    lst.get(l).val = lst.get(r).val;
                    lst.get(r).val = tmp;
                }
            }
            isOdd = !isOdd;
        }
        return root;

    }

    void dfs(TreeNode left, TreeNode right, boolean isOdd) {
        if (left == null) return;
        if (isOdd) {
            int tmp = left.val;
            left.val = right.val;
            right.val = tmp;
        }
        dfs(left.left, right.right, !isOdd);
        dfs(left.right, right.left, !isOdd);
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

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
