package com.sovava._23._12._1954收集足够苹果的最小花园周长;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月24日 0:56
 **/
public class Solution {
    public long minimumPerimeter(long neededApples) {
        long l = (long) Math.floor(Math.pow(neededApples >>> 2, (1.0d / 3.0d)));

        while (2 * l* (((2 * l + 3) * l) * l + 1)  < neededApples) {
            l++;
        }

        return 8 * l;

    }
}
