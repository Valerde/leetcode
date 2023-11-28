package com.sovava._405数字转换为十六进制数;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月28日 10:15 AM
 **/
public class Solution {
    public static String toHex(int num) {
        if (num == 0) {
            return "0";
        }
        char[] c = new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        StringBuilder sb = new StringBuilder();
        for (int i = 7; i >= 0; i--) {

            int right4 = num >> (4 * i) & 0b1111;
            if (sb.length() > 0 || right4 > 0) {
                sb.append(c[right4]);
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(Integer.toBinaryString(-1));
        System.out.println(toHex(-1));
    }
}
