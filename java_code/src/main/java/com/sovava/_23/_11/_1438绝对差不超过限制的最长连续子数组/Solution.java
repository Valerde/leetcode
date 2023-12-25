package com.sovava._23._11._1438绝对差不超过限制的最长连续子数组;

import java.util.*;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月23日 9:41 AM
 **/
public class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> queMax = new LinkedList<>();
        Deque<Integer> queMin = new LinkedList<>();
        int left = 0, right = 0;
        int res = 0;
        int len = nums.length;
        while (right < len) {
            while (!queMax.isEmpty() && queMax.peekLast() < nums[right]) {
                queMax.pollLast();
            }
            while (!queMin.isEmpty() && queMin.peekLast() > nums[right]) {
                queMin.pollLast();
            }
            queMax.offerLast(nums[right]);
            queMin.offerLast(nums[right]);
            while (!queMax.isEmpty() && !queMin.isEmpty() && queMax.peekFirst() - queMin.peekFirst() > limit) {
                if (nums[left] == queMax.peekFirst()) {
                    queMax.pollFirst();
                }
                if (nums[left] == queMin.peekFirst()) {
                    queMin.pollFirst();
                }
                left++;
            }
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;

    }
}
