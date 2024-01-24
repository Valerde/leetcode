package com.sovava._24._01._2865美丽塔;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月24日 8:38 PM
 **/
public class Solution {
    public long maximumSumOfHeights(List<Integer> maxHeights) {
        Deque<Integer> q = new ArrayDeque<>();
        int len = maxHeights.size();
        long[] idx1 = new long[len];
        long[] idx2 = new long[len];

        for (int i = 0; i < len; i++) {
            while (!q.isEmpty() && maxHeights.get(i) < maxHeights.get(q.peekLast())) {
                q.pollLast();
            }
            if (q.isEmpty()) {
                idx1[i] = (long) (i + 1) * maxHeights.get(i);
            } else {
                idx1[i] = (long) idx1[q.peekLast()] + (long) (i - q.peekLast()) * maxHeights.get(i);
            }
            q.offerLast(i);
        }
        q.clear();
        long res = 0;
        for (int i = len - 1; i >= 0; i--) {
            while (!q.isEmpty() && maxHeights.get(i) < maxHeights.get(q.peekLast())) {
                q.pollLast();
            }
            if (q.isEmpty()) {
                idx2[i] = (long) (len - i) * maxHeights.get(i);
            } else {
                idx2[i] = (long) idx2[q.peekLast()] + (long) (q.peekLast() - i) * maxHeights.get(i);
            }
            q.offerLast(i);
            res = Math.max(res, idx2[i] + idx1[i] - maxHeights.get(i));
        }
        return res;
    }
}