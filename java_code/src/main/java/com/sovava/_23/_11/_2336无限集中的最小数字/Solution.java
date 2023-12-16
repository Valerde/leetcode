package com.sovava._23._11._2336无限集中的最小数字;

import java.util.Arrays;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月29日 9:47 AM
 **/
public class Solution {
    class SmallestInfiniteSet {

        private final int[] nums = new int[1001];



        public SmallestInfiniteSet() {
            Arrays.fill(nums, 1);
        }

        public int popSmallest() {
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] == 1) {
                    nums[i] = 0;
                    return i;
                }
            }
            return 1001;
        }

        public void addBack(int num) {
            nums[num] = 1;
        }
    }

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */
}
