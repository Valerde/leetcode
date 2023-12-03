package com.sovava._可获得的最大点数;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月03日 2:55 PM
 **/
public class Solution {
    public int maxScore(int[] cardPoints, int k) {

        int len = cardPoints.length;
        int sum = 0;
        int idx = len - k;
        for (int i = idx; i < len; i++) {
            sum += cardPoints[i];
        }
        int tmp = sum;
        for (int i = 0; i < k; i++) {
            tmp = tmp - cardPoints[(i + idx) % len] + cardPoints[(idx + k + i) % len];
            sum = Math.max(tmp, sum);
        }
        return sum;

    }
}
