package com.sovava._2216美化数组的最少删除数;

import java.util.Arrays;
import java.util.LinkedList;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月21日 10:59 AM
 **/
public class Solution {

    public int minDeletion(int[] nums) {

        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int cnt = 0;
        //此时应该判断偶数，偶数时为true
        boolean check = true;
        for (int i = 0; i < len - 1; i++) {
            if (check && i % 2 == 0 && nums[i] == nums[i + 1]) {
                cnt++;
                check = !check;
            }
            if (!check && i % 2 == 1 && nums[i] == nums[i + 1]) {
                cnt++;
                check = !check;
            }
        }
        if ((len - cnt) % 2 == 1) {
            cnt++;
        }
        return cnt;
    }
}
