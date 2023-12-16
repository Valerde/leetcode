package com.sovava._23._11._1657确定两个字符串是否接近;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月30日 2:33 PM
 **/
public class Solution {
    public boolean closeStrings(String word1, String word2) {

        if (word2.length() != word1.length()) {
            return false;
        }
        char[] chars1 = word1.toCharArray();
        char[] chars2 = word2.toCharArray();
        int len = word1.length();
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];

        int[] flag1 = new int[26];
        int[] flag2 = new int[26];
        for (int i = 0; i < len; i++) {
            cnt1[chars1[i] - 'a']++;
            cnt2[chars2[i] - 'a']++;
            flag1[chars1[i] - 'a'] = 1;
            flag2[chars2[i] - 'a'] = 1;
        }
        for (int i = 0; i < 26; i++) {
            if (flag1[i] != flag2[i]) {
                return false;
            }
        }
        Arrays.sort(cnt1);
        Arrays.sort(cnt2);

        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[10];
        for (int i = 0; i < 10; i++) {
            int i1 = sc.nextInt();

            a[i] = i1;
        }

        for (int i : a) {

            System.out.println(i);
        }

    }
}
