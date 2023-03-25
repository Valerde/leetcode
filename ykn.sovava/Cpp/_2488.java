package Cpp;

import java.util.HashMap;
import java.util.Map;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月16日 10:36
 **/
public class _2488 {
    public int countSubarrays(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        int index = 0;
        while (nums[index] != k) index++;
        int sum = 0;
        for (int i = index - 1; i >= 0; i--) {
            sum+=nums[i]>k?1:-1;
            map.merge(sum,1,Integer::sum);

        }
        sum = 0;
        int res = 1;
        for(int i = index+1;i<n;i++){
            sum+=nums[i]>k?1:-1;
            res+=map.getOrDefault(sum,0)+map.getOrDefault(sum-1,0);
        }
        return res;
    }
}
