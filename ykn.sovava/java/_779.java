package java;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月11日 15:50
 **/
public class _779 {

    public int kthGrammar(int n, int k) {
        if (n == 1 && k == 1) {
            return 0;
        }
        int temp = kthGrammar(n - 1, (k + 1) / 2);
        if (temp == 0 && k % 2 == 1) return 0;
        if (temp == 0 && k % 2 == 0) return 1;
        if (temp == 1 && k % 2 == 1) return 1;
        if (temp == 1 && k % 2 == 0) return 0;
        return 0;
    }

}
