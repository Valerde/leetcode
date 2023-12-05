package com.sovava._2477到达首都的最少油耗;

import java.util.*;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月05日 10:20 AM
 **/
class Solution {
    long res = 0;

    public long minimumFuelCost(int[][] roads, int seats) {
        int n = roads.length + 1;

        List<Integer>[] g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>();
        }

        for (int[] road : roads) {
            g[road[0]].add(road[1]);
            g[road[1]].add(road[0]);
        }
        dfs(0, -1, seats, g);
        return res;
    }

    public int dfs(int cur, int last, int seats, List<Integer>[] g) {
        int peopleNum = 1;
        for (int ne : g[cur]) {
            if (ne != last) {
                int peopleCnt = dfs(ne, cur, seats, g);
                peopleNum += peopleCnt;
                res += (peopleCnt + seats - 1) / seats;
            }
        }
        return peopleNum;
    }
}