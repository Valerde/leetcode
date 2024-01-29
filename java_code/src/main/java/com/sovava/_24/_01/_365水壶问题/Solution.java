package com.sovava._24._01._365水壶问题;


/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月28日 2:48 PM
 **/
public class Solution {
    public boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        if (jug1Capacity == 0 || jug2Capacity == 0) {
            return targetCapacity == 0 || jug1Capacity + jug2Capacity == targetCapacity;
        }
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }

    private int gcd(int a, int b) {
        int tmp = 0;
        while (a % b != 0) {
            tmp = b;
            b = a % b;
            a = tmp;
        }
        return b;
    }

}
