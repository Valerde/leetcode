package com.sovava._23._11._848字母移位;

import java.util.Arrays;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月24日 12:32 PM
 **/
public class Solution {
    public static String shiftingLetters(String s, int[] shifts) {
        int n = shifts.length;
        char[] chars = s.toCharArray();

        shifts[n - 1] %= 26;
        chars[n - 1] = (char) ((chars[n - 1] - 'a' + shifts[n - 1]) % 26 + 'a');
        for (int i = n - 2; i >= 0; i--) {
            shifts[i] %= 26;
            shifts[i] += shifts[i + 1];
            chars[i] = (char) ((chars[i] - 'a' + shifts[i]) % 26 + 'a');
        }

        return new String(chars);
    }

    public static void main(String[] args) {

    }
}
