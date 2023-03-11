package java._316最小字典序;

import org.junit.jupiter.api.Test;

import java.util.Stack;

/**
 * Description:
 *
 * @author: ykn
 * @date: 2022年07月13日 12:35
 **/
public class Solution {
    public String removeDuplicateLetters(String s) {
        char[] chars = s.toCharArray();
        int[] lastIndex = new int[26];
        for (int i = 0; i < chars.length; i++) {
            lastIndex[chars[i] - 'a'] = i;//记录每一个字母最后出现的位置
        }

        boolean[] visited = new boolean[26];//某一字符是否在栈中出现
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < chars.length; i++) {
            if (visited[chars[i] - 'a']) continue;//如果出现就舍弃
            //当前字符在栈顶元素之前，且栈顶元素在后面还有
            while (!stack.isEmpty() && stack.peek() > chars[i] && lastIndex[stack.peek() - 'a'] > i) {
                char ch = stack.pop();//移除栈顶元素
                visited[ch - 'a'] = false;//表示该字符没有在栈中出现
            }
            stack.push(chars[i]);
            visited[chars[i] - 'a'] = true;
        }
        StringBuilder sb = new StringBuilder();
        for (char c : stack) {
            sb.append(c);
        }
        return sb.toString();
    }

    @Test
    public void test() {
        System.out.println(removeDuplicateLetters("bcabc"));
    }
}
