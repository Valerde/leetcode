package com.sovava._24._01._2744最大字符串配对数目;

import java.util.*;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月17日 0:37
 **/
public class Solution {
    public int maximumNumberOfStringPairs(String[] words) {
        boolean[] tab = new boolean[(26 << 5) + 26];
        int res = 0;
        int sec, fir;
        for (String word : words) {
            fir = word.charAt(1) - 97;
            sec = word.charAt(0) - 97;
            if (tab[(fir << 5) | sec]) {
                res++;
            }
            tab[(sec << 5) | fir] = true;
        }
        return res;
    }
}
