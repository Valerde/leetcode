package com.sovava._24._01._410分割数组的最大值;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月21日 17:14
 **/
class Solution {
    public int splitArray(int[] nums, int k) {
        int sum = 0;
        int mx = 0;
        for (int x : nums) {
            sum += x;
            mx = Math.max(mx, x);
        }

        int left = Math.max(mx - 1, (sum - 1) / k);
        int right = sum;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(nums, k, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    private boolean check(int[] nums, int k, int mx) {
        int cnt = 1;
        int s = 0;
        for (int x : nums) {
            if (s + x <= mx) {
                s += x;
            } else { // 新划分一段
                if (cnt == k) {
                    return false;
                }
                cnt += 1;
                s = x;
            }
        }
        return true;
    }
}
