package com.sovava._24._01._466统计重复个数;

import java.util.HashMap;
import java.util.Map;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月02日 0:11
 **/
class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int index1 = 0;
        int index2 = 0;

        if (len1 == 0 || len2 == 0 || len1 * n1 < len2 * n2) {
            return 0;
        }

        Map<Integer, Integer> map1 = new HashMap<>();
        Map<Integer, Integer> map2 = new HashMap<>();
        int ans = 0;

        while (index1 / len1 < n1) {
            if (index1 % len1 == len1 - 1) {
                if (map1.containsKey(index2 % len2)) {
                    int val = map1.get(index2 % len2);
                    int cycleLen = index1 / len1 - val / len1;
                    int cycleNum = (n1 - 1 - index1 / len1) / cycleLen;
                    int cycleS2Num = index2 / len2 - map2.get(index2 % len2) / len2;

                    index1 += cycleNum * cycleLen * len1;
                    ans += cycleNum * cycleS2Num;
                } else {
                    map1.put(index2 % len2, index1);
                    map2.put(index2 % len2, index2);
                }
            }

            if (s1.charAt(index1 % len1) == s2.charAt(index2 % len2)) {
                if (index2 % len2 == len2 - 1) {
                    ans += 1;
                }
                index2 += 1;
            }
            index1 += 1;
        }
        return ans / n2;
    }
}
