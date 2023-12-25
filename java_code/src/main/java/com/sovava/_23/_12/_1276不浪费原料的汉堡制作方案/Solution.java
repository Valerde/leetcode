package com.sovava._23._12._1276不浪费原料的汉堡制作方案;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月25日 0:22
 **/
public class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int a = tomatoSlices - (cheeseSlices << 1);
        int b = (cheeseSlices << 2) - tomatoSlices;

        if (a < 0 || b < 0 || a % 2 == 1 || b % 2 == 1) {
            return new ArrayList<>();
        } else {
            return Arrays.asList((a >> 1), b >> 1);
        }
    }
}
