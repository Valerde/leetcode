package com.sovava._24._01._2707字符串中的额外字符;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月09日 21:20
 **/
public class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        Set<String> set = new HashSet<>(Arrays.asList(dictionary));
        int len = s.length();
        int[] dp = new int[len + 1];
        dp[1] = set.contains(String.valueOf(s.charAt(0))) ? 0 : 1;
        for (int i = 1; i < len; i++) {
            dp[i + 1] = dp[i] + 1;
            for (int j = 0; j <= i; j++) {
                if (set.contains(s.substring(j, i + 1))) {
                    dp[i + 1] = Math.min(dp[i + 1], dp[j]);
                }
            }
        }
        return dp[len];
    }
}
