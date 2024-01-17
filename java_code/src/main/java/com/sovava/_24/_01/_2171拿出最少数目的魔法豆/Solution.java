package com.sovava._24._01._2171拿出最少数目的魔法豆;

import java.util.Arrays;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月18日 0:25
 **/
public class Solution {
    public long minimumRemoval(int[] beans) {
        Arrays.sort(beans);
        int len = beans.length;
        long total = 0;
        for (int bean : beans)
            total += bean;

        long res = total;
        for (int i = 0; i < len; i++) {
            res = Math.min(res, total - (long) beans[i] * (len - i));
        }
        return res;
    }
}
