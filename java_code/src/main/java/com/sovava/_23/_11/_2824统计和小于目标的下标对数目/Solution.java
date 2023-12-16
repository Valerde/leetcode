package com.sovava._23._11._2824统计和小于目标的下标对数目;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月24日 12:16 PM
 **/
public class Solution {
    public static int countPairs(List<Integer> nums, int target) {
        nums.sort(Comparator.comparingInt(o -> o));

        int res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++) {
            while (i < j && nums.get(i) + nums.get(j) < target) {
                j--;
            }
            res+=j-i;
        }

        return res;

    }

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>() {
            {
                add(3);
                add(2);
                add(1);
                add(4);
            }
        };
        countPairs(list, 2);
    }
}
