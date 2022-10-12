package java._8字符串转换整数;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年07月02日 12:00
 **/
public class Solution {
    public static int myAtoi(String s) {

        //int len = s.length();
        int result = 0;
        boolean vgfu = true;
        int i = 0;
        if (s.length() == 0) return 0;
        while (s.charAt(i) == ' ') {
            if (s.length() - 1 == i) return 0;
            i++;
        }
        if (s.charAt(i) == '-') {
            vgfu = false;
            i++;
        } else if (s.charAt(i) == '+') i++;
        for (; i < s.length(); i++) {
            if (s.charAt(i) - '0' >= 0 && s.charAt(i) - '0' < 10) {
                if (vgfu && (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && s.charAt(i) - '0' > 7)))
                    return Integer.MAX_VALUE;
                else if (!vgfu && (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && s.charAt(i) - '0' > 8)))
                    return Integer.MIN_VALUE;
                else
                    result = result * 10 + s.charAt(i) - '0';
            } else break;
        }
        if (!vgfu) return -result;
        return result;
    }

    public static void main(String[] args) {
        System.out.println(myAtoi(" 12"));
    }
}
