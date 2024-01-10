package com.sovava._24._01._2696删除子串后的字符串最小长度;


class Solution {
    public int minLength(String s) {
        char[] chars = s.toCharArray();
        int len = chars.length;
        char[] stack = new char[len];
        int res = len;
        int top = 0;
        stack[top] = chars[0];
        for (int i = 1; i < len; i++) {

            if (top >= 0 && ((stack[top] == 'A' && chars[i] == 'B') || (stack[top] == 'C' && chars[i] == 'D'))) {
                top--;
                res -= 2;
            } else {
                stack[++top] = chars[i];
            }
        }
        return res;
    }
}