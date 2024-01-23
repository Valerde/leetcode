package com.sovava._24._01._2765最长交替子数组;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月23日 23:11
 **/
public class Solution {
    public int alternatingSubarray(int[] nums) {
        int res = -1;
        int n = nums.length;
        int firstIndex = 0;
        for (int i = 1; i < n; i++) {
            int length = i - firstIndex + 1;
            if (nums[i] - nums[firstIndex] == (length - 1) % 2) {
                res = Math.max(res, length);
            } else {
                if (nums[i] - nums[i - 1] == 1) {
                    firstIndex = i - 1;
                    res = Math.max(res, 2);
                } else {
                    firstIndex = i;
                }
            }
        }
        return res;
    }

}
