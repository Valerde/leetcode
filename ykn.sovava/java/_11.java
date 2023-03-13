package java;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月13日 13:03
 **/
public class _11 {
    public int maxArea(int[] height) {
        int i = 0;
        int n = height.length;
        int j = n - 1;
        int max = (j - i) * Math.min(height[i], height[j]);
        while (i < j) {
            if (height[i] < height[j]) {
                int tempI = i;
                while (height[tempI] <= height[i]) {
                    i++;
                    max = (j - i) * Math.min(height[i], height[j]);
                }
            }else{
                int tempJ = j;
                while (height[tempJ] <= height[j]) {
                    j--;
                    max = (j - i) * Math.min(height[i], height[j]);
                }
            }
        }
        return max;
    }
}
