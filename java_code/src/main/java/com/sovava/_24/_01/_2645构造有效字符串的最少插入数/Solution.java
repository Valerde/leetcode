package com.sovava._24._01._2645构造有效字符串的最少插入数;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月11日 20:12
 **/
public class Solution {
    public int addMinimum(String word) {
        int len = word.length();
        int cnt = 1;
        for (int i = 1; i < len; i++) {
            if (word.charAt(i) <= word.charAt(i - 1)) {
                cnt++;
            }
        }
        return 3 * cnt - len;
    }
}
