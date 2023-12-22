package com.sovava._23._12._1671得到山形数组的最少删除次数;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月22日 14:24
 **/
class Solution {
    public int minimumMountainRemovals(int[] nums) {

        int len = nums.length;
        int[] reverse = getReverse(nums, len);

        int[] lis = new int[len];
        int[] revlis = new int[len];
        for (int i = 0; i < len; i++) {
            int lengthOfLIS = lengthOfLIS(Arrays.copyOfRange(nums, 0, i + 1));
            lis[i] = lengthOfLIS;
        }

        int res = Integer.MIN_VALUE;
        for (int i = 0; i < len; i++) {
            int lengthOfLIS = lengthOfLIS(Arrays.copyOfRange(reverse, 0, i + 1));
            revlis[len - 1 - i] = lengthOfLIS;
        }
        for (int i = 0; i < len; i++) {
            if (lis[i] != 1 && revlis[i] != 1) {
                res = Math.max(lis[i] + revlis[i] - 1, res);
            }

        }
        return len - res;
    }

    private int[] getReverse(int[] nums, int len) {
        int[] reverse = new int[len];
        for (int i = 0; i < nums.length; i++) {
            reverse[i] = nums[len - 1 - i];
        }
        return reverse;

    }


    public int lengthOfLIS(int[] nums) {
        List<Integer> list = new ArrayList<>();
        list.add(nums[0]);
        for (int num : nums) {
            int j = binarySearch(list, num);
            if (j == list.size()) list.add(num);
            else list.set(j, num);
        }
        return list.size();

    }

    private int binarySearch(List<Integer> g, int target) {
        int l = -1, r = g.size();// 开区间

        while (l + 1 < r) {
            int mid = (l + r) >>> 1;
            if (g.get(mid) < target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
    }
}
