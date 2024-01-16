package com.sovava._24._01._2719统计整数数目;

import java.util.Arrays;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月16日 22:07
 **/
class Solution {

    public int count(String num1, String num2, int minSum, int maxSum) {
        int n = num2.length();
        num1 = new String(new char[n - num1.length()]).replace("\0", "0") + num1; // 补前导零，和 num2 对齐

        int[][] memo = new int[n][Math.min(9 * n, maxSum) + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        return dfs(0, 0, true, true, num1.toCharArray(), num2.toCharArray(), minSum, maxSum, memo);
    }

    private int dfs(int i, int sum, boolean limitLow, boolean limitHigh, char[] num1, char[] num2, int minSum, int maxSum, int[][] memo) {
        if (sum > maxSum) { // 非法
            return 0;
        }
        if (i == num2.length) {
            return sum >= minSum ? 1 : 0;
        }
        if (!limitLow && !limitHigh && memo[i][sum] != -1) {
            return memo[i][sum];
        }

        int lo = limitLow ? num1[i] - '0' : 0;
        int hi = limitHigh ? num2[i] - '0' : 9;

        int res = 0;
        for (int d = lo; d <= hi; d++) { // 枚举当前数位填 d
            res = (res + dfs(i + 1, sum + d, limitLow && d == lo, limitHigh && d == hi,
                    num1, num2, minSum, maxSum, memo)) % 1_000_000_007;
        }

        if (!limitLow && !limitHigh) {
            memo[i][sum] = res;
        }
        return res;
    }
}


