package com.sovava._23._12._1094拼车;


/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月02日 9:52 AM
 **/
public class Solution {
    public boolean carPooling(int[][] trips, int capacity) {

        int toMax = 0;
        for (int[] trip : trips) {
            toMax = Math.max(toMax, trip[2]);
        }
        int[] diff = new int[toMax + 1];
        for (int[] trip : trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }
        int res = 0;
        for (int i = 0; i <= toMax; i++) {
            res += diff[i];
            if (res > capacity) {
                return false;
            }
        }
        return true;
    }
}
