package com.sovava._24._01._1944队列中可以看到的人数;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月05日 14:26
 **/
public class Solution {
    public int[] canSeePersonsCount(int[] heights) {

        int len = heights.length;
        int[] res = new int[len];
        Deque<Integer> q = new ArrayDeque<>(len);


        for(int i = len -1;i>=0;i--){
            while(!q.isEmpty()&&q.peek()<heights[i]){
                q.pop();
                res[i]++;
            }

            if(!q.isEmpty()){
                res[i]++;
            }
            q.push(heights[i]);
        }
        return res;

    }
}
