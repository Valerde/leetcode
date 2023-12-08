package com.sovava._1331数组序号转换;

import java.util.*;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月08日 10:29 AM
 **/
public class Solution {
    public int[] arrayRankTransform(int[] arr) {

        int[] arr1 = Arrays.copyOf(arr, arr.length);
        Arrays.sort(arr);
        int idx = 1;
        Map<Integer, Integer> map = new HashMap<>(arr.length / 2);
        for (int j : arr) {
            if (!map.containsKey(j)) {
                map.put(j, idx);
                idx++;
            }
        }
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = map.get(arr1[i]);
        }

        return arr1;
    }
}
