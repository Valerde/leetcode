package com.sovava._23._12._1631最小体力消耗路径;

import java.util.*;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月11日 1:49 PM
 **/
public class Solution {

    int N = 10009;
    int[] p = new int[N];
    int row, col;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void union(int a, int b) {
        p[find(a)] = p[find(b)];
    }

    boolean query(int a, int b) {
        return p[find(a)] == p[find(b)];
    }

    public int minimumEffortPath(int[][] heights) {

        row = heights.length;
        col = heights[0].length;

        //初始化并查集
        for (int i = 0; i < col * row; i++) {
            p[i] = i;
        }

        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int idx = getIndex(i, j);
                if (i + 1 < row) {
                    int a = idx, b = getIndex(i + 1, j);
                    int w = Math.abs(heights[i][j] - heights[i + 1][j]);
                    edges.add(new int[]{a, b, w});
                }
                if (j + 1 < col) {
                    int a = idx, b = getIndex(i, j + 1);
                    int w = Math.abs(heights[i][j] - heights[i][j + 1]);
                    edges.add(new int[]{a, b, w});
                }
            }
        }


        edges.sort(Comparator.comparingInt(o -> o[2]));
        int start = getIndex(0, 0), end = getIndex(row - 1, col - 1);
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            union(a, b);
            if (query(start, end)) {
                return w;
            }


        }
        return 0;
    }


    int getIndex(int x, int y) {
        return x * col + y;
    }
}


class Solution2 {
    int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int minimumEffortPath(int[][] heights) {
        int m = heights.length;
        int n = heights[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(edge -> edge[2]));
        pq.offer(new int[]{0, 0, 0});

        int[] dist = new int[m * n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;
        boolean[] seen = new boolean[m * n];

        while (!pq.isEmpty()) {
            int[] edge = pq.poll();
            int x = edge[0], y = edge[1], d = edge[2];
            int id = x * n + y;
            if (seen[id]) {
                continue;
            }
            if (x == m - 1 && y == n - 1) {
                break;
            }
            seen[id] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && Math.max(d, Math.abs(heights[x][y] - heights[nx][ny])) < dist[nx * n + ny]) {
                    dist[nx * n + ny] = Math.max(d, Math.abs(heights[x][y] - heights[nx][ny]));
                    pq.offer(new int[]{nx, ny, dist[nx * n + ny]});
                }
            }
        }

        return dist[m * n - 1];
    }
}


class Solution3 {
    int[] dx = new int[]{0, 1, 0, -1}, dy = new int[]{1, 0, -1, 0};
    int n, m, res = Integer.MAX_VALUE;
    boolean[][] vis;

    public int minimumEffortPath(int[][] heights) {
        n = heights.length;
        m = heights[0].length;

        int r = 1000000 - 1, l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(heights, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    public boolean check(int[][] h, int val) {
        vis = new boolean[n][m];
        return dfs(h, 0, 0, val);
    }

    public boolean dfs(int[][] h, int x, int y, int val) {
        if (x == (n - 1) && y == (m - 1)) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]
                    && Math.abs(h[x][y] - h[nx][ny]) <= val) {
                vis[nx][ny] = true;
                if (dfs(h, nx, ny, val)) {
                    return true;
                }
            }
        }
        return false;
    }
}
