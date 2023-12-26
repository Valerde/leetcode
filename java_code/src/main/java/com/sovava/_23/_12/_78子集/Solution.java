package com.sovava._23._12._78子集;

import java.util.ArrayList;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月26日 19:35
 **/
public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int len = nums.length;
        int n = 1 << len;
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<>());
        for (int i = 0; i < n; i++) {
            int a = i;
            List<Integer> list = new ArrayList<>();
            int t = 0;
            while (a > 0) {
                if ((a & 1) == 1) {
                    list.add(nums[t]);
                }
                a = a >> 1;
                t++;
            }
            res.add(list);
        }
        return res;
    }
}
