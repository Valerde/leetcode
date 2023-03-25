package Cpp;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月15日 12:10
 **/
public class _55 {
    public boolean canJump(int[] nums) {
        int mstep = 0;
        int now = 0;
        int ago = 0;
        int n = nums.length;
        while (now < n - 1) {
            mstep = nums[now];
            ago = now;
            now = now + mstep;
            int temp = now;
            for (int i = ago; i < now; i++) {
                if(i+nums[i]>now){
                    ago = i;
                    now = i+nums[i];
                }
            }
            if (temp == now && nums[now]==0) return false;
        }
        return true;
    }
}
