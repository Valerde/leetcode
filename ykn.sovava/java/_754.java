package java;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月11日 17:07
 **/
public class _754 {
    public int reachNumber(int target) {
        int step = 1;
        int sum = 0;
        target = Math.abs(target);
        while(sum<target){
            sum+=step;
            step++;
        }
        if (sum == target){
            return step;
        }else if ((sum - target) %2 ==0){
            return step;
        }else {
            return step+2;
        }
    }
}
