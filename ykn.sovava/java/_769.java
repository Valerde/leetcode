package java;


import org.testng.annotations.Test;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月11日 16:02
 **/
public class _769 {
    public static int maxChunksToSorted(int[] arr) {
        int minNum = 0, maxNum = 0;
        int minInd = 0, maxInd = 0;
        int n = arr.length - 1;
        int cnt = 0;
        int i = 0;
        for (; i <= n; ) {

            if (i != arr[i]) {
                minInd = i;
                minNum = arr[i];
                maxNum = arr[i];
                maxInd = i;
                for (int j = i; j <= n; j++) {
                    if (minInd == minNum && maxInd == maxNum) {
                        i = j + 1;
                        cnt++;
                        break;
                    }
                    minNum = Math.min(minNum, arr[j]);
                    maxNum = Math.max(maxNum,arr[j]);
                }
            } else {
                cnt++;
                i++;
            }
        }
        return cnt;
    }

    @Test
    void test(){
        int[] arr = {1,0,2,3,4};
        int i = maxChunksToSorted(arr);
        System.out.println(i);
    }

}
