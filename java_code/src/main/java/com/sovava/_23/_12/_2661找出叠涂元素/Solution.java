package com.sovava._23._12._2661找出叠涂元素;

import java.util.HashMap;
import java.util.Map;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月01日 2:03 PM
 **/
public class Solution {
    public static int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int mn = arr.length;

        int qd = 200000;

        Map<Integer, Long> map = new HashMap<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map.put(mat[i][j], ((long) i * qd + j));
            }
        }
        int[] mflag = new int[m];
        int[] nflag = new int[n];

        for (int i = 0; i < mn; i++) {
            long aLong = map.get(arr[i]);
            int n1 = (int) (aLong % qd);
            int m1 = (int) (aLong / qd);
            mflag[m1]++;
            nflag[n1]++;
            if (mflag[m1] == n || nflag[n1] == m) {
                return i;
            }

        }

        return mn - 1;
    }

}
