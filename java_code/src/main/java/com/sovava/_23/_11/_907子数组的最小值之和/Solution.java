package com.sovava._23._11._907子数组的最小值之和;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Queue;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月27日 1:06 PM
 **/
class Solution {


    public int sumSubarrayMins(int[] arr) {
        int len = arr.length;
        Deque<Integer> q = new ArrayDeque<>();
        int[][] m = new int[len][2];
        for (int i = 0; i < len; i++) {
            while (!q.isEmpty() && arr[q.peek()] > arr[i]) {
                q.pop();
            }
            m[i][0] = q.isEmpty() ? -1 : q.peek();
            q.push(i);
        }

        q.clear();
        for (int i = len - 1; i >= 0; i--) {
            while (!q.isEmpty() && arr[q.peek()] >= arr[i]) {
                q.pop();
            }
            m[i][1] = q.isEmpty() ? len : q.peek();
            q.push(i);
        }
        final int mod = 1000000007;
        long res = 0;
        for (int i = 0; i < len; i++) {
            res = (res + ((long) (i - m[i][0]) * (m[i][1] - i) * arr[i])) % mod;
        }
        return (int) res;

    }
}
