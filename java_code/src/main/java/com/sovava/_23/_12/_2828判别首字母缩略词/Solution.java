package com.sovava._23._12._2828判别首字母缩略词;

import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月20日 12:18
 **/
public class Solution {

    public boolean isAcronym(List<String> words, String s) {

        if (words.size() != s.length()) {
            return false;
        }
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (words.get(i).charAt(0) != s.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}
