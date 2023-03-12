package java;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月12日 13:15
 **/
public class _121 {
    public int maxProfit(int[] prices) {
        int length = prices.length;
        int minNum = Integer.MAX_VALUE,max = 0;
        for(int i = 1;i<length;i++){
            minNum = Math.min(prices[i-1],minNum);
            max = Math.max(prices[i]-minNum,0);
        }
        return max;
    }
}
