package java.jmvioffer55;

import org.junit.Test;

/**
 * Description: 自底向上递归
 *
 * @author: ykn
 * @date: 2022年07月13日 1:18
 **/
class Solution {
    public boolean isBalanced(TreeNode root) {
        return height(root) >= 0;
    }

    public int height(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (Math.abs(height(root.left) - height(root.right)) > 1 || height(root.left) == -1 || height(root.right) == -1) {
            return -1;
        } else {
            return Math.max(height(root.right), height(root.left)) + 1;
        }
    }

    @Test
    public void test() {
//        System.out.println(isBalanced());
    }
}
