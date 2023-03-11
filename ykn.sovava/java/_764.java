package java;

import java.util.Arrays;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月11日 16:33
 **/
public class _764 {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        int grid[][] = new int[n][n];
        for (int i = 0; i < n; i++) Arrays.fill(grid[i], 1);
        for (int i = 0; i < mines.length; i++) grid[mines[i][0]][mines[i][1]] = 0;
        int dp[][][] = new int[n][n][4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[i][j][0] = grid[i][j];
                } else {
                    if (grid[i][j] == 0) {
                        dp[i][j][0] = 0;
                    } else {
                        dp[i][j][0] = dp[i][j - 1][0] + 1;
                    }

                }

            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (j == n - 1) {
                    dp[i][j][1] = grid[i][j];
                } else {
                    if (grid[i][j] == 0) {
                        dp[i][j][1] = 0;
                    } else {
                        dp[i][j][1] = dp[i][j - 1][1] + 1;
                    }

                }

            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[i][j][2] = grid[i][j];
                } else {
                    if (grid[i][j] == 0) {
                        dp[i][j][2] = 0;
                    } else {
                        dp[i][j][2] = dp[i][j - 1][2] + 1;
                    }

                }

            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i == n - 1) {
                    dp[i][j][3] = grid[i][j];
                } else {
                    if (grid[i][j] == 0) {
                        dp[i][j][3] = 0;
                    } else {
                        dp[i][j][3] = dp[i][j - 1][3] + 1;
                    }

                }

            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int temp = Math.max(Math.max(dp[i][j][0], dp[i][j][1]), Math.max(dp[i][j][2], dp[i][j][3]));
                res = Math.max(res, temp);
            }
        }
        return res;
    }
}
