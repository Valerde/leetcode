package java._84柱状图中最大的矩形;

import org.junit.Test;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

/**
 * Description: 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * <p>
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 * @author: ykn
 * @date: 2022年07月15日 14:51
 **/
public class Solution {
    public int largestRectangleArea_OverTime(int[] heights) {
        int temp = heights[0];
        int ret = temp;
        int min = temp;
        for (int i = 1; i < heights.length; i++) {
            min = heights[i];
            for (int j = i; j >= 0; j--) {
                if (heights[j] == 0)
                    break;
                min = Math.min(min, heights[j]);
                temp = (i - j + 1) * min;
                if (temp > ret)
                    ret = temp;

            }
        }
        return ret;
    }//超时
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        int[] a = new int[len];
        int[] b = new int[len];
        Arrays.fill(b,len);
        Deque<Integer> mono_stack = new ArrayDeque<>();
        for (int i = 0;i<len;i++){
            while (!mono_stack.isEmpty()&&heights[mono_stack.peek()]>=heights[i]){
                b[mono_stack.peek()] = i;
                mono_stack.pop();
            }
            a[i]=mono_stack.isEmpty()?-1:mono_stack.peek();
            mono_stack.push(i);
        }

        mono_stack.clear();

//        for (int i = len-1;i>=0;i--){
//            while (!mono_stack.isEmpty()&&heights[mono_stack.peek()]>=heights[i]){
//                mono_stack.pop();
//            }
//            b[i] = mono_stack.isEmpty()?len:mono_stack.peek();
//            mono_stack.push(i);
//        }
        int ans = 0;
        for (int i = 0;i<len;i++){
            ans = Math.max(ans,(b[i]-a[i]-1)*heights[i]);
        }
        return ans;
    }
    @Test
    public void test() {
        System.out.println(largestRectangleArea(new int[]{4,2,0,3,2,5}));
    }
}
