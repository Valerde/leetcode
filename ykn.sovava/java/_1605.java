package java;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月14日 12:13
 **/
public class _1605 {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int n = rowSum.length, m = colSum.length;
        int[][] res = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int min = Math.min(rowSum[i],colSum[j]);
                res[i][j] = min;
                rowSum[i] -=min;
                colSum[j] -= min;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println("haha");
    }
}
