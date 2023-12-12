package com.sovava._2454下一个更大元素IV;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月12日 10:10 PM
 **/
class Solution {
    public int[] secondGreaterElement(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        Arrays.fill(res, -1);
        List<Integer> stack1 = new ArrayList<>();
        List<Integer> stack2 = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stack2.isEmpty() && nums[stack2.get(stack2.size() - 1)] < v) {
                res[stack2.get(stack2.size() - 1)] = v;
                stack2.remove(stack2.size() - 1);
            }
            int pos = stack1.size() - 1;
            while (pos >= 0 && nums[stack1.get(pos)] < v) {
                --pos;
            }
            for (int j = pos + 1; j < stack1.size(); j++) {
                stack2.add(stack1.get(j));
            }
            for (int j = stack1.size() - 1; j >= pos + 1; j--) {
                stack1.remove(j);
            }
            stack1.add(i);
        }
        return res;
    }
}


