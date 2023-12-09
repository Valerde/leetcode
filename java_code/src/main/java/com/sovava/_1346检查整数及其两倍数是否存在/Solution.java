package com.sovava._1346检查整数及其两倍数是否存在;

import java.util.HashSet;
import java.util.Set;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月09日 1:22 PM
 **/
public class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> set = new HashSet<>();

        for (int num : arr) {
            if (set.contains(num * 2) || (num % 2 == 0 && set.contains(num / 2))) {
                return true;
            } else {
                set.add(num);
            }
        }
        return false;
    }
}
