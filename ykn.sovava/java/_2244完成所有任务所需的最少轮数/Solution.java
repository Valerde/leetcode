package java._2244完成所有任务所需的最少轮数;


import org.junit.jupiter.api.Test;

import java.util.Arrays;

/**
 * Description: 给你一个下标从 0 开始的整数数组 tasks ，其中 tasks[i] 表示任务的难度级别。
 * 在每一轮中，你可以完成 2 个或者 3 个 相同难度级别 的任务。
 * <p>
 * 返回完成所有任务需要的 最少 轮数，如果无法完成所有任务，返回 -1 。
 * <p>
 * 示例 1：
 * <p>
 * 输入：tasks = [2,2,3,3,2,4,4,4,4,4]
 * 输出：4
 * 解释：要想完成所有任务，一个可能的计划是：
 * - 第一轮，完成难度级别为 2 的 3 个任务。
 * - 第二轮，完成难度级别为 3 的 2 个任务。
 * - 第三轮，完成难度级别为 4 的 3 个任务。
 * - 第四轮，完成难度级别为 4 的 2 个任务。
 * 可以证明，无法在少于 4 轮的情况下完成所有任务，所以答案为 4 。
 * <p>
 *
 *
 * 9ms 95%<br>
 * 50.5 MB 91%
 * @author: ykn
 * @date: 2022年07月06日 19:59
 **/
public class Solution {
    public int minimumRounds(int[] tasks) {
        int len = tasks.length;
        if (len < 2) {
            return -1;
        }
        Arrays.sort(tasks);
        int temp = tasks[0];
        int count = 0;
        int tempCount = 0;
        boolean flag = false;//flag用来标记当前任务难度级别有没有3个的,如果有三个的,就可以把3+1转化为2+2
        for (int i = 0; i < len; i++) {
            if (temp != tasks[i]) {//跳转下一个
                temp = tasks[i];//记录当前所在的难度组
                if (tempCount == 2) {
                    count++;
                    tempCount = 0;
                } else if (tempCount == 1) {
                    if (!flag)
                        return -1;
                    else {//flag用来标记当前任务难度级别有没有3个的,如果有三个的,就可以把3+1转化为2+2
                        count++;
                        tempCount = 0;
                    }
                }
                tempCount++;
                flag = false;
            } else {//当前难度组计数
                tempCount++;
                if (tempCount == 3) {
                    count++;
                    tempCount = 0;
                    flag = true;
                }
            }
        }
        if (tempCount == 1) {
            if (!flag)
                return -1;
            else
                count++;

        } else if (tempCount == 2) {
            count++;
        }

        return count;
    }

    @Test
    public void test() {
        int[] tasks = {2, 2, 2, 3, 3, 4, 4, 4, 4, 4};
        System.out.println(minimumRounds(tasks));
    }
}
