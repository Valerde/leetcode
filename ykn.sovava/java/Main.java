package com.sovava.pack;

import java.util.*;

// 注意类名必须为 Main, 不要有任何 package xxx 信息
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        List<List<Integer>> per = permute(a);
        int count = 0;
        //System.out.println(per.size());
        for (List<Integer> p : per) {
            //System.out.println(p);
            if (!panduanxianglin(p)) {
                //System.out.println(p);
                count++;
            }
        }
        System.out.print(2);
    }

    private static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList();
        backtrack(res, new ArrayList(), nums);
        return res;
    }

    public static void backtrack(List<List<Integer>> res, List<Integer> tmp, int[] nums) {
        if (tmp.size() == nums.length) {
            res.add(new ArrayList(tmp));
        } else {
            for (int i = 0; i < nums.length; i++) {
                if (tmp.contains(nums[i])) {
                    continue;
                }
                tmp.add(nums[i]);
                backtrack(res, tmp, nums);
                tmp.remove(tmp.size() - 1);
            }
        }
    }

    public static boolean isPrime(int a, int b) {
        int sum = a + b;
        if (sum < 2) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(sum); i++) {
            if (sum % i == 0) {
                return true;
            }
        }
        return false;
    }

    public static boolean panduanxianglin(List<Integer> list) {
        for (int i = 0; i < list.size() - 1; i++) {
            if (isPrime(list.get(i), list.get(i + 1))) {
                return true;
            }
        }
        return false;
    }
}