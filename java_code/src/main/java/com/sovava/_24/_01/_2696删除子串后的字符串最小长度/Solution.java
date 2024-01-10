package com.sovava._24._01._2696删除子串后的字符串最小长度;

import java.util.ArrayList;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月10日 23:28
 **/
public class Solution {
    public int minLength(String s) {
        List<Character> stack = new ArrayList<Character>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            stack.add(c);
            int m = stack.size();
            if (m >= 2 &&
                    (stack.get(m - 2) == 'A' && stack.get(m - 1) == 'B' ||
                            stack.get(m - 2) == 'C' && stack.get(m - 1) == 'D')) {
                stack.remove(m - 1);
                stack.remove(m - 2);
            }
        }
        return stack.size();
    }
}
