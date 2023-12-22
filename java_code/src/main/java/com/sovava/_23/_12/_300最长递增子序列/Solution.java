package com.sovava._23._12._300最长递增子序列;

import java.util.ArrayList;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月22日 13:49
 **/
public class Solution {
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

        while (l+1 < r) {
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
