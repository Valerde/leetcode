package com.sovava._935骑士拨号器;


import java.util.Arrays;


/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月27日 2:11 PM
 **/
public class Solution {
    public int knightDialer(int n) {
        int[][] nodes = new int[][]{
                {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
        };
        int[][] res = new int[2][10];
        Arrays.fill(res[0], 1);
        for (int i = 0; i < n; i++) {
            Arrays.fill(res[(i + 1) % 2], 0);
            for (int j = 0; j < 10; j++) {
                for (int node : nodes[j]) {
                    res[(i + 1) % 2][node] += res[i % 2][j];
                    res[(i + 1) % 2][node] %= 1000000007;
                }
            }
        }
        long ans = 0;
        for (int r : res[(n + 1) % 2]) {
            ans += r;
            ans %= 1000000007;
        }
        return (int) ans;
    }
}
