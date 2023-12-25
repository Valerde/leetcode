package com.sovava._23._12._162寻找峰值;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月18日 1:22
 **/
public class Solution {

    public int findPeakElement(int[] nums) {

        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > nums[mid + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
