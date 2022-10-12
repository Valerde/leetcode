package java._2186使两字符串互为字母异位词的最少步骤数;

import org.junit.Test;

/**
 * Description: 给你两个字符串 s 和 t 。在一步操作中，你可以给 s 或者 t 追加 任一字符 。
 * <p>
 * 返回使 s 和 t 互为 字母异位词 所需的最少步骤数。
 * <p>
 * 字母异位词 指字母相同但是顺序不同（或者相同）的字符串。
 * <p>
 *
 * @author: ykn
 * @date: 2022年07月15日 1:01
 **/
public class Solution {
//    public int minSteps(String s, String t) {
//        StringBuilder sb1 = new StringBuilder(s);
//        StringBuilder sb2 = new StringBuilder(t);
//        int len1 = sb1.length();
//        int len2 = sb2.length();
//        for (int i = 0; i < len1; i++) {
//            for (int j = 0; j < len2; j++) {
//                if (sb1.charAt(i) == sb2.charAt(j)) {
//                    sb1.deleteCharAt(i);
//                    sb2.deleteCharAt(j);
//
//                    len2--;
//                    len1--;
//                    i--;
//                    break;
//                }
//            }
//        }
//        return len1 + len2;
//    }超时

    public int minSteps(String s, String t) {
        int[] chn = new int[26];
        char[] chars1 = s.toCharArray();
//        char[] chars2 = t.toCharArray();
//        for (int i = 0;i<s.length();i++){
//            chn[s.charAt(i)-'a']++;
//        }
        for (char c : chars1) {
            chn[c - 'a']++;
        }
//        for (int i = 0;i<t.length();i++){
//            chn[t.charAt(i)-'a']--;
//        }
        chars1 = t.toCharArray();
        for (char c : chars1) {
            chn[c - 'a']--;
        }
        int ret = 0;
        for (int a : chn) {
            ret += a>0?a:-a;
        }
//        if (ret==6784)return 400000;
        return ret;
    }

    @Test
    public void test() {
        System.out.println(minSteps("cotxazilut", "nahrrmcchxwrieqqdwdpneitkxgnt"));
    }
}
