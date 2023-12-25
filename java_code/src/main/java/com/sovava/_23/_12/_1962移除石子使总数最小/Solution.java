package com.sovava._23._12._1962移除石子使总数最小;

import java.util.*;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月23日 0:38
 **/
public class Solution {
    public int minStoneSum(int[] piles, int k) {
        Queue<Integer> q = new PriorityQueue<>(2 * k, (o1, o2) -> o2 - o1);

        int sum = 0;

        int len = piles.length;
        for (int i = 0; i < len; i++) {
            q.offer(piles[i]);
            sum += piles[i];
        }

        int subTotal = 0;

        for (int i = 0; i < k; i++) {
            int pop = q.poll();
            int sub = pop >>> 1;
            subTotal += sub;
            q.offer(pop - sub);
        }
        return sum - subTotal;
    }
}
