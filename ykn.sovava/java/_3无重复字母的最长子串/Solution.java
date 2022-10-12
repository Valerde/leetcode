package java._3无重复字母的最长子串;

import java.util.*;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年06月27日 14:14
 **/
public class Solution {
    public static int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int max = 0;

        for (int i = 0,j = 0; j < s.length(); j++) {
            char alpha = s.charAt(j);
            if (map.containsKey(alpha)) {
                i = Math.max(map.get(alpha), i);
            }
            max = Math.max(max, j-i + 1);
            map.put(s.charAt(j), j + 1);
        }

        return max;

    }

    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring("aab"));
    }
}