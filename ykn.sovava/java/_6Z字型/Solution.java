package java._6Z字型;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年07月02日 12:02
 **/

public class Solution {
    public static String convert(String s, int numRows) {
        int len = s.length();
        char[] chars = s.toCharArray();
        int t = 2 * numRows - 2;
        StringBuilder sb = new StringBuilder();
        if (numRows == 1) return s;
        //i为行数
        for (int i = 0; i < numRows; i++) {
            sb.append(chars[i]);
            //j为直行的列数

            for (int j = 1; ; j++) {

                try {
                    if ((i == 0 || i == numRows - 1))
                        sb.append(chars[i + j * t]);
                    else {
                        sb.append(chars[j * t - i]);
                        sb.append(chars[j * t + i]);
                    }

                } catch (IndexOutOfBoundsException e) {
                    break;
                }

            }
            if (sb.length() == len) {
                return sb.toString();
            }
        }
        return sb.toString();

    }

    public static void main(String[] args) {
        System.out.println(convert("A", 2));
    }
}
