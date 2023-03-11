package java;

import java.util.Arrays;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月11日 17:26
 **/
public class _698 {
    int[] nums;
    int k, n, per;

    public boolean canPartitionKSubsets(int[] _nums, int _k) {
        k = _k;
        nums = _nums;
        n = nums.length;
        boolean flag[] = new boolean[n];
        Arrays.fill(flag, false);
        int sum = Arrays.stream(nums).sum();
        if (sum % k != 0) return false;
        Arrays.sort(nums);
        per = sum / k;
        if (nums[n - 1] > per) return false;

        return dfs(n - 1, 0, 0, flag);

    }

    public boolean dfs(int ind, int cur, int cnt, boolean flag[]) {
        if (cnt == k) return true;
        if (cur == per) return dfs(n - 1, 0, cnt++, flag);
        for (int i = ind; i >= 0; i--) {
            if (flag[i] || cur + nums[i] > per) continue;
            flag[i] = true;
            if (dfs(i - 1, cur + nums[i], cnt, flag)) return true;
            flag[i] = false;
            if (cur == 0) return false;
        }
        return false;
    }
}
