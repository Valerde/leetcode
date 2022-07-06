package _541反转字符串2;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年07月04日 15:09
 **/
public class Solution {
    public static String reverseStr(String s, int k) {
//        int len = ;
        int lastLen = s.length();//last是剩余未处理的字符串
        StringBuilder sb = new StringBuilder();
        StringBuilder sbRet = new StringBuilder();
        int index = 0;
        while (true) {
            if (lastLen >= k) {
                sb.delete(0, sb.length());
                sb.append(s.substring(index, index + k));
                sb.reverse();
                sbRet.append(sb);
                if (lastLen >= 2 * k) {
                    sbRet.append(s.substring(index + k, index + 2 * k));
                    index += 2 * k;
                    lastLen -= 2 * k;
                } else {
                    sbRet.append(s.substring(index + k));
                    break;
                }

            } else {
                sb.delete(0, sb.length());
                sb.append(s.substring(index));
                sb.reverse();
                sbRet.append(sb);
                break;
            }
        }
        return sbRet.toString();
    }

    public static void main(String[] args) {
        System.out.println(reverseStr("abcdefg", 2));
    }

    //官方题解,在有时间和内存要求下,最好自己写函数,比如此题的reverse
    public String GRFHreverseStr(String s, int k) {
        int n = s.length();
        char[] arr = s.toCharArray();
        for (int i = 0; i < n; i += 2 * k) {
            reverse(arr, i, Math.min(i + k, n) - 1);
        }
        return new String(arr);
    }

    public void reverse(char[] arr, int left, int right) {
        while (left < right) {
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

}
