package com.sovava._24._01._2859计算K置位下标对应元素的和;

import java.util.Iterator;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月25日 12:54 AM
 **/
public class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        if (k == 0) {
            return nums.get(0);
        }
        Iterator<Integer> it = nums.iterator();
        int i = 0;
        int tmp, res = 0;

        while (it.hasNext()) {
            tmp = it.next();
            if (check(i) == k) {

                res += tmp;
            }
            i++;
        }
        return res;

    }

    private int check(int i) {
        int res = 0;
        while (i > 0) {
            res += (i & 1);
            i >>= 1;
        }
        return res;
    }
}
