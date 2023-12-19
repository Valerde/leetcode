package com.sovava._23._12._1901寻找峰值2;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月19日 0:54
 **/
public class Solution {
    public int[] findPeakGrid(int[][] mat) {


        int m = mat.length;
        int n = mat[0].length;
        int left = 0, right = m - 1;
        while (left <= right) {
            int middle = (left + right) >> 1;
            int j = -1, maxElement = -1;
            for (int k = 0; k < n; k++) {
                if (mat[middle][k] > maxElement) {
                    j = k;
                    maxElement = mat[middle][k];
                }
            }
            if (middle - 1 >= 0 && mat[middle][j] < mat[middle - 1][j]) {
                right = middle - 1;
                continue;
            }
            if (middle + 1 < m && mat[middle][j] < mat[middle + 1][j]) {
                left = middle + 1;
                continue;
            }
            return new int[]{middle, j};
        }

        return new int[0];
    }
}
