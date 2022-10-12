package java._7整数反转;

import java.util.ArrayList;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年07月02日 12:06
 **/
public class Solution {
    //我以为这样快,实际上这样慢多了,只击败了15%,然而确实一遍过的
    public static int reverse(int x) {
        boolean flag = false;
        if (x < 0) {
            flag = true;
            x = -x;
        }
        List<Integer> list = new ArrayList<>();
        if (x == 0) {
            return x;
        }
        while (x > 0) {
            list.add(x % 10);
            x /= 10;
        }
        for (int i = 0, j = list.size() - 1; i <= j; i++, j--) {
            int temp = list.get(i);
            list.set(i, list.get(j));
            list.set(j, temp);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < list.size(); i++) {
            sb.append(list.get(i));
        }
        //System.out.println(sb);
        try {
            int ret = Integer.parseInt(sb.reverse().toString());
            //int asd = Integer.parseInt("4294967296");
            if (flag == true) {
                return -ret;
            } else
                return ret;
        } catch (NumberFormatException e) {
            return 0;
        }


    }

    public static int NEWreverse(int x) {
        int ans = 0;
        while (x != 0) {
            int pop = x % 10;
            if (ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && pop > 7))
                return 0;
            if (ans < Integer.MIN_VALUE / 10 || (ans == Integer.MIN_VALUE / 10 && pop < -8))
                return 0;
            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;

    }

    public static void main(String[] args) {
        System.out.println(NEWreverse(-12111134));

    }
}
