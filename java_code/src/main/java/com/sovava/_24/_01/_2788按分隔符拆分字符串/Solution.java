package com.sovava._24._01._2788按分隔符拆分字符串;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Pattern;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月20日 23:01
 **/
public class Solution {

    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> res = new ArrayList<String>();
        StringBuilder sb = new StringBuilder();
        char[] chars;
        for (String word : words) {
            sb.setLength(0);
            int length = word.length();
            chars = word.toCharArray();
            for (int i = 0; i < length; i++) {
                char c = chars[i];
                if (c == separator) {
                    if (sb.length() > 0) {
                        res.add(sb.toString());
                        sb.setLength(0);
                    }
                } else {
                    sb.append(c);
                }
            }
            if (sb.length() > 0) {
                res.add(sb.toString());
            }
        }
        return res;
    }
}


class Solution1 {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> ans = new ArrayList<>();
        for (String w : words) {
            for (String s : w.split(Pattern.quote(String.valueOf(separator)))) {
                if (s.length() > 0) {
                    ans.add(s);
                }
            }
        }
        return ans;
    }
}
