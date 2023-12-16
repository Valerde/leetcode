package com.sovava._23._11._41缺失的第一个正数;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月25日 10:29 AM
 **/
class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (nums[i] <= 0) {
                nums[i] = len + 1;
            }
        }

        for (int i = 0; i < len; i++) {
            if (Math.abs(nums[i]) <= len) {
                nums[Math.abs(nums[i]) - 1] = -Math.abs(nums[Math.abs(nums[i]) - 1]);
            }
        }
        int i = 0;
        for (; i < len; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return len + 1;
    }
}
