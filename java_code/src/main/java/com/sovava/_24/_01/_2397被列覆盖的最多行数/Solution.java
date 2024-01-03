package com.sovava._24._01._2397被列覆盖的最多行数;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月04日 0:24
 **/
public class Solution {
    public int maximumRows(int[][] matrix, int numSelect) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i] |= matrix[i][j] << (n - j - 1);
            }
        }

        int num = (1 << numSelect) - 1;
        int limit = 1 << n;
        int res = 0;

        while (num < limit) {
            if (Integer.bitCount(num) != numSelect) {
                num++;
                continue;
            }
            int tmp = 0;
            for (int i = 0; i < m; i++) {
                if ((a[i] & num) == a[i]) {
                    tmp++;
                }
            }
            res = Math.max(res, tmp);
            num++;
        }
        return res;
    }
}
