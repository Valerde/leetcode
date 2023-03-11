package java;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月11日 15:41
 **/
public class _788 {
    int[] a = {0,0,1,-1,-1,1,1,-1,0,1};
    public int rotatedDigits(int n) {
        int count = 0;
        for(int i = 0;i<n;i++){
            count+=judge(i);
        }
        return count;
    }
    public int judge(int num){
        boolean b = false;
        while(num>0){
            int temp= num%10;
            if (a[temp] == -1){
                return 0;
            }else if (a[temp] == 1){
                b = true;
            }
            num/=10;
        }
        return b?1:0;
    }
}
