package _1200最小绝对差;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2022年07月04日 14:52
 **/
public class Solution {
    public static List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> list = new ArrayList<>();
        int d = 0, a = 0, b = 0;
        int temp = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length - 1; i++) {
            a = arr[i + 1];
            b = arr[i];
            d = a - b;
            if (d < temp) {
                temp = d;
                list.clear();
                List<Integer> slist = new ArrayList<>();
                slist.add(b);
                slist.add(a);
                list.add(slist);
            } else if (d == temp) {
                List<Integer> slist = new ArrayList<>();
                slist.add(b);
                slist.add(a);
                list.add(slist);
            }
        }
        return list;
    }

    public static void main(String[] args) {
        int[] arr = {3, 8, -10, 23, 19, -4, -14, 27};
        System.out.println(minimumAbsDifference(arr));
    }
}
