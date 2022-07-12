package _1851;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.PriorityQueue;

/**
 * Description: 给你一个二维整数数组 intervals ，
 * 其中 intervals[i] = [lefti, righti] 表示第 i 个区间开始于 lefti 、结束于 righti（包含两侧取值，闭区间）。
 * 区间的 长度 定义为区间中包含的整数数目，更正式地表达是 righti - lefti + 1 。
 * <p>
 * 再给你一个整数数组 queries 。第 j 个查询的答案是满足 lefti <= queries[j] <= righti 的 长度最小区间 i 的长度 。
 * 如果不存在这样的区间，那么答案是 -1 。
 * <p>
 * 以数组形式返回对应查询的所有答案。
 * <p>
 * 示例 1：
 * <p>
 * 输入：intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
 * 输出：[3,3,1,4]
 * 解释：查询处理如下：
 * - Query = 2 ：区间 [2,4] 是包含 2 的最小区间，答案为 4 - 2 + 1 = 3 。
 * - Query = 3 ：区间 [2,4] 是包含 3 的最小区间，答案为 4 - 2 + 1 = 3 。
 * - Query = 4 ：区间 [4,4] 是包含 4 的最小区间，答案为 4 - 4 + 1 = 1 。
 * - Query = 5 ：区间 [3,6] 是包含 5 的最小区间，答案为 6 - 3 + 1 = 4 。
 * <p>
 *
 * @author: ykn
 * @date: 2022年07月13日 0:03
 **/
public class Solution {
    public static int[] minInterval(int[][] intervals, int[] queries) {

        //先按左端点从小到大排序
        Arrays.sort(intervals, (o1, o2) -> o1[0] - o2[0]);
        //因为我们之后要排序queries数组，但是答案又要按顺序输出，所以我们这里用一个二维数组来保存要查询的值和其下标
        int[][] que = new int[queries.length][2];
        for (int i = 0; i < queries.length; i++) {
            que[i][0] = queries[i];
            que[i][1] = i;
        }
        //按查询数组升序排列
        Arrays.sort(que, (v1, v2) -> v1[0] - v2[0]);
        int[] ans = new int[queries.length];
        //默认ans数组所有值都不存在最小区间，如果之后找到了最小区间会覆盖
        Arrays.fill(ans, -1);
        //创建优先队列,按照区间长度升序排列 TODO:优先级队列
        PriorityQueue<int[]> queue = new PriorityQueue<>((o1, o2) -> (o1[1] - o1[0]) - (o2[1] - o2[0]));
        //遍历intervals左区间的位置
        int index = 0;
        for (int i = 0; i < queries.length; i++) {
            //将所有起始位置小于等于查询位置的区间intervals[i]添加到优先队列中
            while (index < intervals.length && que[i][0] >= intervals[index][0]) {
                queue.offer(new int[]{intervals[index][0], intervals[index][1]});
                index++;
            }
            //将队列中不能覆盖要查询点的区间移除队列
            while (!queue.isEmpty() && queue.peek()[1] < que[i][0])
                queue.poll();
            //如果队列不为空，则代表队首区间是要查询的点的最短区间
            if (!queue.isEmpty()) {
                int[] t = queue.peek();
                ans[que[i][1]] = t[1] - t[0] + 1;   //que[i][1]代表这个查询原来的下标
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] intervals = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
        int[] queries = {2, 3, 4, 5};
        int[] a = minInterval(intervals, queries);
        for (int i :
                a) {
            System.out.println(i);
        }
    }
}
