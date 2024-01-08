package com.sovava._24._01._447回旋镖的数量;

import java.util.HashMap;
import java.util.Map;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月08日 17:18
 **/
public class Solution {
    public int numberOfBoomerangs(int[][] points) {

        int len = points.length;
        if(len<3) return 0;
        int res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            map.clear();
            for (int j = 0; j < len; j++) {
                if (i == j) continue;
                int x = (points[i][0] - points[j][0]);
                int y = (points[i][1] - points[j][1]);
                int distance = x * x + y * y;
                Integer num = map.getOrDefault(distance, 0);
                res += num <<1;
                map.put(distance, num + 1);
            }
        }
        return res;
    }
}
