package com.sovava.other.huaweiInterview;

import java.util.*;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月21日 10:57 AM
 **/
public class HuaWei {


    public static int[] topk(int nums[], int k) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : nums) {
            Integer cnt = map.getOrDefault(num, 0);
            cnt++;
            map.put(num, cnt);
        }

        Map<Integer, Integer> reverse = new HashMap<>();

        for (Map.Entry<Integer, Integer> ent : map.entrySet()) {
            reverse.put(ent.getValue(), ent.getKey());
        }

        Queue<Integer> q = new PriorityQueue<>(k, (o1, o2) -> o2 - o1);
        for (Map.Entry<Integer, Integer> ent : map.entrySet()) {
            Integer value = ent.getValue();
            q.offer(value);
        }

        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = reverse.get(q.poll());
        }

        return res;
    }

    public static void main(String[] args) {
        int[] in = new int[]{1, 1, 1, 2, 2, 3};
        int[] topk = topk(in, 2);
        System.out.println(Arrays.toString(topk));


        int[] in2 = new int[]{1};
        int[] topk2 = topk(in2, 1);
        System.out.println(Arrays.toString(topk2));

    }
}
