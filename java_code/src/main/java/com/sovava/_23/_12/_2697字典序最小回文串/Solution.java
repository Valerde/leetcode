package com.sovava._23._12._2697字典序最小回文串;

import java.util.Arrays;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月13日 11:31
 **/
public class Solution {
    public String makeSmallestPalindrome(String s) {
        char[] chars = s.toCharArray();
        int fir = 0, lst = s.length() - 1;
        while (fir < lst) {
            if (chars[fir] < chars[lst]) {
                chars[lst] = chars[fir];
            } else {
                chars[fir] = chars[lst];
            }
            fir++;
            lst++;
        }

        return String.valueOf(chars);
    }
}
