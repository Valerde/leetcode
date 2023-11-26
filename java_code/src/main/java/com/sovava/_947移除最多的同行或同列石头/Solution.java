package com.sovava._947移除最多的同行或同列石头;

import java.util.HashMap;
import java.util.Map;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月26日 1:23 PM
 **/
public class Solution {
    public int removeStones(int[][] stones) {
        UnionFind unionFind = new UnionFind();
        for (int[] stone : stones) {
            unionFind.union(stone[0], stone[1] + 10001);
        }

        return stones.length - unionFind.getCnt();
    }

    public class UnionFind {
        private Map<Integer, Integer> parent;
        private int cnt;

        public UnionFind() {
            this.parent = new HashMap<>();
            this.cnt = 0;
        }

        public int getCnt() {
            return cnt;
        }

        public int find(int p) {
            if (!parent.containsKey(p)) {
                parent.put(p, p);
                cnt++;
            }
            if (p != parent.get(p)) {
                parent.put(p, find(parent.get(p)));
            }
            return parent.get(p);
        }

        public void union(int x, int y) {
            int X = find(x);
            int Y = find(y);
            if (X == Y) {
                return;
            }
            parent.put(X, Y);
            cnt--;
        }
    }
}
