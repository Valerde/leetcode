package java._1两数之和;

import java.util.HashMap;
import java.util.Map;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年07月02日 12:01
 **/
public class Solution {

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int i = 0;
        for (i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i]))
                return new int[]{map.get(target - nums[i]), i};
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
