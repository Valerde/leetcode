package com.sovava._24._01._1599经营摩天轮的最大利润;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月01日 21:52
 **/
class Solution {
    public int minOperationsMaxProfit(int[] customers, int boardingCost, int runningCost) {
        int len = customers.length;

        int wheel = -1;
        int profit = 0;
        int down = 0;
        int up = 0;
        for (int i = 0; i < len || down > 0; i++) {
            if (i < len)
                down += customers[i];
            int val = Math.min(4, down);
            down -= val;
            up += val;
            val = up * boardingCost - (i+1) * runningCost;
            if (val > profit) {
                profit = val;
                wheel = i+1;
            }
        }
        return wheel;
    }
}
