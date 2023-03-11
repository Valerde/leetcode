package java;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月11日 19:53
 **/
public class _540 {
    public int singleNonDuplicate(int[] nums) {
        if (nums.length == 1) return nums[0];
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (right - left == 2) return nums[left] ^ nums[left + 1] ^ nums[right];
            if (nums[mid] == nums[mid + 1] && mid % 2 == 1) right = mid - 1;
            else if (nums[mid] == nums[mid + 1] && mid % 2 == 0) left = mid;
            else if (nums[mid] == nums[mid - 1] && mid % 2 == 1) left = mid + 1;
            else if (nums[mid] == nums[mid - 1] && mid % 2 == 0) right = mid;
            else return nums[mid];
        }
        return 0;
    }
}
