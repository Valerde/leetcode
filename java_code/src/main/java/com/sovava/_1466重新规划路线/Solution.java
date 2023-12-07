package com.sovava._1466重新规划路线;

import java.util.ArrayList;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月07日 12:05 PM
 **/
public class Solution {
    private int res = 0;

    public int minReorder(int n, int[][] connections) {

        List<int[]>[] e = new List[n];

        for (int i = 0; i < n; i++) {
            e[i] = new ArrayList<>();
        }

        for (int[] connection : connections) {
            e[connection[0]].add(new int[]{connection[1], 1});
            e[connection[1]].add(new int[]{connection[0], 0});
        }

        dfs(0, -1, e);
        return res;
    }

    private void dfs(int x, int parent, List<int[]>[] e) {
        for (int[] edge : e[x]) {
            if (edge[0] == parent) {
                continue;
            }
            res += edge[1];
            dfs(edge[0], x, e);
        }
    }


}
