package java._面试题0508绘制直线;

import org.junit.Test;

/**
 * Description: 已知一个由像素点组成的单色屏幕，每行均有 w 个像素点，所有像素点初始为 0，左上角位置为 (0,0)。
 * <p>
 * 现将每行的像素点按照「每 32 个像素点」为一组存放在一个 int 中，再依次存入长度为 length 的一维数组中。
 * <p>
 * 我们将在屏幕上绘制一条从点 (x1,y) 到点 (x2,y) 的直线（即像素点修改为 1），请返回绘制过后的数组。
 * <p>
 * 输入：length = 1, w = 32, x1 = 30, x2 = 31, y = 0
 * 输出：[3]
 * 解释：在第 0 行的第 30 位到第 31 位画一条直线，屏幕二进制形式表示为 [00000 00000 00000 00000 00000 00000 11]，因此返回 [3]
 * <p>
 *
 * @author: ykn
 * @date: 2022年07月05日 20:56
 **/
public class Solution {

    /*
    执行用时：0 ms, 在所有 Java 提交中击败了100.00%的用户
    内存消耗：41.6 MB, 在所有 Java 提交中击败了94.04%的用户
     */
    public int[] drawLine(int length, int w, int x1, int x2, int y) {
        int[] ret = new int[length];
        int a1 = y * w / 32 + x1 / 32;
        int b1 = x1 % 32;
        int a2 = y * w / 32 + x2 / 32;
        int b2 = x2 % 32;
        ret[a1] = -1;
        ret[a2] = -1;
        if (a1 == a2) {
            ret[a1] = ret[a1] >>> (32 - b2 + b1 - 1);
        } else {
            ret[a1] = ret[a1] >>> (b1);
        }
        ret[a2] = ret[a2] << (32 - b2 - 1);

        for (int i = a1 + 1; i < a2; i++) {
            ret[i] = -1;
        }
        return ret;
    }

    //24
    //96
    //2
    //19
    //5
    @Test
    public void test() {
//        System.out.println(8>>2);
        int[] ints = drawLine(24, 96, 2, 19, 5);
        for (int anInt : ints) {
            System.out.println(anInt);
        }

    }

}
