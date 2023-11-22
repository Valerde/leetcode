package com.sovava._2126摧毁小行星;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月22日 7:49 PM
 **/
public class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {

        Arrays.sort(asteroids);
        for (int asteroid : asteroids) {
            if (mass <= asteroid) {
                mass += asteroid;
            } else {
                return false;
            }
        }
        return true;
    }
}
