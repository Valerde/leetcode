package com.sovava._24._01._565数组嵌套;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月19日 0:15
 **/
public class Solution {
    public int arrayNesting(int[] nums) {
        int res = 0;
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            int cnt = 0;
            int head = i;
            while (nums[head] > -1) {
                int next = nums[head];
                nums[head] = -1;
                head = next;
                cnt++;
            }
            res = Math.max(res, cnt);
            if (res > (len >> 1)) {
                return res;
            }
        }
        return res;
    }
}
