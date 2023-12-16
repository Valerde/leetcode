package com.sovava._23._12._1642可以到达的最远建筑;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月15日 21:48
 **/
public class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {

        int len = heights.length;

//        PriorityQueue<Integer> q = new PriorityQueue<>((o1, o2) -> o2 - o1);
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int i = 0; i < len - 1; i++) {
            int sub = heights[i + 1] - heights[i];
            if (sub > 0) {
                q.offer(sub);
                bricks -= sub;

                if (bricks < 0) {
                    if (ladders > 0) {
                        ladders--;
                        bricks += q.poll();
                    } else {
                        return i;
                    }
                }

            }
        }
        return len - 1;

    }


    class Solution1 {
        public int furthestBuilding(int[] heights, int bricks, int ladders) {
            int n = heights.length, sum = 0;
            Queue<Integer> queue = new PriorityQueue<>();
            for (int i = 1; i < heights.length; i++) {
                int diff = heights[i] - heights[i - 1];
                if (diff > 0) {
                    queue.offer(diff);
                    if (queue.size() > ladders) {
                        sum += queue.poll();
                    }
                    if (sum > bricks)
                        return i - 1;
                }
            }
            return n - 1;
        }
    }

    public static void main(String[] args) {
        Queue<Node> q = new PriorityQueue<>();
        q.offer(new Node("ykn",14));
        q.offer(new Node("hjy",12));
        System.out.println(Arrays.toString(q.toArray()));
    }

   static class Node implements Comparable<Node>{
        String s;
        int age;
        Node(String s,int a){
            this.s = s;
            this.age = a;
        }

       @Override
       public String toString() {
           return "Node{" +
                   "s='" + s + '\'' +
                   ", age=" + age +
                   '}';
       }

       @Override
       public int compareTo(Node o) {
           return this.age-o.age;
       }
   }
}
