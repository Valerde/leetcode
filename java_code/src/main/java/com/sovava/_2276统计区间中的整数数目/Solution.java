package com.sovava._2276统计区间中的整数数目;

import java.util.Map;
import java.util.TreeMap;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月16日 12:42
 **/
public class Solution {
    class CountIntervals {
        TreeMap<Integer, Integer> map = new TreeMap<>();

        int cnt = 0;

        public CountIntervals() {

        }

        public void add(int left, int right) {
            Map.Entry<Integer, Integer> integerEntry = map.floorEntry(right);
            while (integerEntry != null && integerEntry.getValue() >= left) {
                int l = integerEntry.getKey();
                int r = integerEntry.getValue();
                left = Math.min(l, left);
                right = Math.max(right, r);
                cnt -= r - l + 1;
                map.remove(l);
                integerEntry = map.floorEntry(right);
            }
            cnt += right - left + 1;
            map.put(left, right);
        }

        public int count() {
            return cnt;
        }
    }
}
