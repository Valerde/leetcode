package com.sovava.pack;


import java.util.Stack;


/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月16日 11:09
 **/
public class _394 {
    public String decodeString(String s) {
        Stack<Integer> numStk = new Stack<>();
        Stack<String> strStk = new Stack<>();

        StringBuffer ans = new StringBuffer();
        int muli = 0;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                muli = muli * 10 + c - '0';
            } else if (c == '[') {
                strStk.push(ans.toString());
                numStk.push(muli);
                ans = new StringBuffer();
                muli = 0;
            } else if (Character.isAlphabetic(c)) {
                ans.append(c);

            } else {
                String pop = strStk.pop();
                Integer pop1 = numStk.pop();
                StringBuffer temp = new StringBuffer(pop);

                for (int i = 0; i < pop1; i++) {
                    temp.append(ans);
                }
                ans = temp;
            }
        }
        return ans.toString();
    }


}
