package com.sovava._23._12._2735收集巧克力;

import java.util.Arrays;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月28日 13:57
 **/
public class Solution {
    public long minCost(int[] nums, int x) {
        int len = nums.length;
        int[][] dp = new int[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][0] = nums[i];
            for (int j = 1; j < len; j++) {
                dp[i][j] = Math.min(dp[i][j - 1], nums[(i - j + len) % len]);
            }
        }

        long res = Long.MAX_VALUE;
        for (int j = 0; j < len; j++) {
            long r = (long) x * j;
            for (int i = 0; i < len; i++) {
                r += dp[i][j];
            }
            res = Math.min(res, r);
        }
        return res;

    }

}
