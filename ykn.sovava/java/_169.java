package java;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月12日 13:30
 **/
public class _169 {
    public int majorityElement(int[] nums) {
        int can = nums[0];
        int cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                can = num;
            }
            cnt += num == can ? 1 : -1;
        }
        return can;
    }
}
