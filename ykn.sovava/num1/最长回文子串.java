package num1;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年07月01日 20:45
 **/
public class 最长回文子串 {
    public class Solution {

        public String longestPalindrome(String s) {
            int len = s.length();
            if (len < 2) {
                return s;
            }

            int maxLen = 1;
            int begin = 0;
            // dp[i][j] 表示 s[i..j] 是否是回文串
            boolean[][] dp = new boolean[len][len];
            // 初始化：所有长度为 1 的子串都是回文串
            for (int i = 0; i < len; i++) {
                dp[i][i] = true;
            }

            char[] charArray = s.toCharArray();
            // 递推开始
            // 先枚举子串长度
            for (int L = 2; L <= len; L++) {
                // 枚举左边界，左边界的上限设置可以宽松一些
                for (int i = 0; i < len; i++) {
                    // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                    int j = L + i - 1;
                    // 如果右边界越界，就可以退出当前循环
                    if (j >= len) {
                        break;
                    }

                    if (charArray[i] != charArray[j]) {
                        dp[i][j] = false;
                    } else {
                        if (j - i < 3) {
                            dp[i][j] = true;
                        } else {
                            dp[i][j] = dp[i + 1][j - 1];
                        }
                    }

                    // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                    if (dp[i][j] && j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        begin = i;
                    }
                }
            }
            return s.substring(begin, begin + maxLen);
        }
    }

    public class mysolution {
        public String longestPalindrome(String s) {
            int length = s.length();
            //dp[i][j]表示s[i~j]是回文串
            boolean[][] dp = new boolean[length][length];
            if (length < 2) {
                return s;
            }
            int max = 1;
            int begin = 0;
            for (int i = 0; i < length; i++) {
                dp[i][i] = true;
            }
            //从最小的回文子串开始
            for (int L = 2; L <= length; L++) {
                //j=i+L-1
                for (int i = 0; i < length; i++) {
                    int j = i + L - 1;
                    if (j >= length) break;

                    if (s.charAt(i) != s.charAt(j)) {//charAT慢
                        dp[i][j] = false;
                    } else {
                        if ((j - i) < 3) {
                            dp[i][j] = true;
                        } else {
                            dp[i][j] = dp[i + 1][j - 1];
                        }
                    }


                    if (dp[i][j] && (j - i + 1) > max) {
                        max = j - i + 1;
                        begin = i;
                    }
                }
            }
            return s.substring(begin, begin + max);
        }
    }
}
