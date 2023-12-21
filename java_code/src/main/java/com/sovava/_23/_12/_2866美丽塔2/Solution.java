package com.sovava._23._12._2866美丽塔2;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.List;

/**
 * Description: https://leetcode.cn/problems/beautiful-towers-ii/solutions/2574217/javapython3cqian-hou-zhui-he-dan-diao-zh-6fxl/?envType=daily-question&envId=2023-12-21
 *
 * @author: ykn
 * @date: 2023年12月21日 12:27
 **/
public class Solution {
    @SuppressWarnings({"null", "unused", "ConstantConditions"})
    public long maximumSumOfHeights(List<Integer> maxHeights) {

        int len = maxHeights.size();
        long[] sufSums = new long[len];//后缀和数组
        Deque<Integer> q = new ArrayDeque<>();
        q.offerLast(len);//栈底为len表示后缀和边界
        long sufs = 0;//后缀和
        for (int i = len - 1; i >= 0; i--) {
            while (q.size() > 1 && maxHeights.get(i) <= maxHeights.get(q.peekLast())) {
                //在到达栈底之前,弹出当前位置右侧的小于等于当前位置高度的最大索引
                int pop = q.pollLast();
                sufs -= (long) (q.peekLast() - pop) * maxHeights.get(pop);
            }
            sufs += (long) maxHeights.get(i) * (q.peekLast() - i);
            sufSums[i] = sufs;
            q.offerLast(i);
        }
        q.clear();
        q.offerLast(-1);//栈底为1表示前缀和边界
        long res = 0;//结果值
        long preS = 0;//前缀和

        for (int i = 0; i < len; i++) {
            while (q.size() > 1 && maxHeights.get(i) <= maxHeights.get(q.peekLast())) {
                int pop = q.pollLast();
                preS -= (long) maxHeights.get(pop) * (pop - q.peekLast());
            }
            preS += (long) maxHeights.get(i) * (i - q.peekLast());
            res = Math.max(res, preS + sufSums[i] - maxHeights.get(i));
            q.offerLast(i);
        }


        return res;
    }
}
