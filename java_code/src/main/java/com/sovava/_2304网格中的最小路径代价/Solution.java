package com.sovava._2304网格中的最小路径代价;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月22日 12:49 PM
 **/
public class Solution {
    public int minPathCost(int[][] grid, int[][] moveCost) {

        int m = grid.length;
        int n = grid[0].length;

        int[][] dp = new int[m][n];
        System.arraycopy(grid[0], 0, dp[0], 0, n);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int min = Integer.MAX_VALUE;
                for (int k = 0; k < n; k++) {
                    min = Math.min(min, dp[i-1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
                dp[i][j] = min;
            }
        }
        int res = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            res = Math.min(res, dp[m - 1][j]);
        }
        return res;
    }
}
