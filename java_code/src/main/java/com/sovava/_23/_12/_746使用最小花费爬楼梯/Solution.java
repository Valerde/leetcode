package com.sovava._23._12._746使用最小花费爬楼梯;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月17日 12:03
 **/
public class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int len = cost.length;
        int[] dp = new int[len];

        dp[0] = dp[1] = 0;

        for (int i = 2; i < len; i++) {
            dp[i] = Math.min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[len-1];


    }
}
