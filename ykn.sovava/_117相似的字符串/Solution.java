package _117相似的字符串;

import org.junit.Test;

/**
 * Description: 如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。
 * <p>
 * 例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。
 * <p>
 * 总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
 * <p>
 * 给定一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个 字母异位词 。请问 strs 中有多少个相似字符串组？
 * <p>
 * 字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。
 * <p>
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/H6lPxb
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author: ykn
 * @date: 2022年07月04日 15:39
 **/
public class Solution {
    int f[];
    boolean aled[];

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        int m = n;
        f = new int[n];
        aled = new boolean[n];
        for (int i = 0; i < n; i++) {
            f[i] = i;
            aled[i] = false;
        }
        for (int i = 0; i < n; i++) {
            if (!aled[i])
                for (int j = i + 1; j < n; j++) {
                    if (check(strs[i], strs[j]) && union(i, j) && !aled[j]) {
                        m--;
                        aled[i] = false;
                        aled[j] = false;
                    }
                }
        }

        return m;
    }

    public boolean union(int i, int j) {
        int a = findFather(i);
        int b = findFather(j);
        if (a != b) {
            f[a] = b;
            return true;
        }
        return false;
    }

    public int findFather(int i) {
        if (f[i] != i) {
            f[i] = findFather(f[i]);
        }
        return f[i];
    }

    public boolean check(String s1, String s2) {
        int count = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i))
                count++;
        }
        return count <= 2;

    }

    @Test
    public void test() {
        String[] strs = {"tars","rats","arts","star"};
        System.out.println(numSimilarGroups(strs));
    }
}
