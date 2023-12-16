package com.sovava._23._12._2132用邮票贴满网格图;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月14日 12:55
 **/
class Solution {
    public boolean possibleToStamp(int[][] grid, int stampHeight, int stampWidth) {
        int m = grid.length, n = grid[0].length;

        //计算grid的前缀和
        int[][] s = new int[m + 1][n + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j]+grid[i][j];
            }
        }

        //计算二维差分
        int[][] d = new int[m + 2][n + 2];
        for (int i = stampHeight; i <= m; i++) {
            for (int j = stampWidth; j <= n; j++) {
                int i1 = i - stampHeight + 1;
                int j1 = j - stampWidth + 1;
                if (s[i][j] - s[i1 - 1][j] - s[i][j1 - 1] + s[i1 - 1][j1 - 1] == 0) {
                    d[i1][j1]++;
                    d[i1][j+1]--;
                    d[i+1][j1]--;
                    d[i+1][j+1]++;
                }
            }
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                d[i+1][j+1] += d[i+1][j]+d[i][j+1]-d[i][j];
                if(grid[i][j] == 0&&d[i+1][j+1] == 0 ){
                    return false;
                }
            }
        }

        return true;
    }
}