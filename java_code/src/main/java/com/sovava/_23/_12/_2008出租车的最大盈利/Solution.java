package com.sovava._23._12._2008出租车的最大盈利;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月07日 12:23 AM
 **/
public class Solution {
    public long maxTaxiEarnings(int n, int[][] rides) {
        long[] dp = new long[n + 1];
        Map<Integer, List<int[]>> map = new HashMap<>();

        for (int[] ride : rides) {
            map.putIfAbsent(ride[1], new ArrayList<>());
            map.get(ride[1]).add(ride);
        }

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (int[] ride : map.getOrDefault(i, new ArrayList<>())) {
                dp[i] = Math.max(dp[i], dp[ride[0]] + ride[1] - ride[0] + ride[2]);
            }
        }
        return dp[n];
    }
}
