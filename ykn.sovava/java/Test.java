package ykn.sovava.java;

import com.sun.deploy.util.OrderedHashSet;

import java.util.*;
import java.util.concurrent.locks.AbstractQueuedSynchronizer;
import java.util.concurrent.locks.ReentrantLock;
import java.util.stream.Collectors;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月14日 21:47
 **/
public class Test {
    public static void main(String[] args) {
//        System.out.println("haha");
//        Scanner scanner = new Scanner(System.in);
//        int n = scanner.nextInt();
//        int[] an = new int[n];
//
//        for (int i = 0; i < n; i++) {
//            an[i] = scanner.nextInt();
//        }
//        System.out.println(an);

//        Stack<Integer> stack = new Stack<>();
//        final List<Integer> x = new ArrayList<Integer>();
//        List<Integer> as = x;
//        as = new ArrayList<>();
//        as.add(1);
//        System.out.println(as);
////        x = as;
//        Integer[] a = new Integer[3];
//        for (int i = 0; i < 3; i++) a[i] = i;
//        for (int an : a) System.out.println(an);
//        swap(a, a[0], a[2]);
//
//        for (int an : a) System.out.println(an);


//        int i=3;
//        Integer j = new Integer(3);
//        Integer k = new Integer(3);
//        Object o = new Object();
//        System.out.println(i==j);
//        System.out.println(j.equals(i));
//        System.out.println(j.equals(k));
//        System.out.println(j==k);
//        System.out.println(o);
        Object o1 = new Object();
        Object o2 = new Object();
        System.out.println(o1.hashCode() + "   " + o2.hashCode());
    }

    public static void swap(Integer[] an, Integer a, Integer b) {
//        int p1 = an[1], p2 = an[2];
//        int temp = an[1];
//        an[1] = an[2];
//        an[2] = temp;
        int temp = a;
        a = b;
        b = temp;
    }

    public int maximalNetworkRank(int n, int[][] roads) {
        Map<Integer, Integer> map = new HashMap<>();
        Boolean[][] connect = new Boolean[n][n];
        int[] degree = new int[n];

        for (int[] point : roads) {
            connect[point[0]][point[1]] = true;
            connect[point[1]][point[0]] = true;
            degree[point[0]]++;
            degree[point[1]]++;
        }
        int first = -1;
        int second = -2;
        List<Integer> firA = new ArrayList<>();
        List<Integer> secA = new ArrayList<>();

        for (int i = 0; i < degree.length; i++) {
            if (degree[i] > first) {
                second = first;
                secA = new ArrayList<>(firA);
                first = degree[i];
                firA.clear();
                firA.add(i);
            } else if (first == degree[i]) {
                firA.add(i);
            } else if (degree[i] > second) {
                secA.clear();
                secA.add(i);
                second = degree[i];
            } else if (degree[i] == second) {
                secA.add(i);
            }
        }

        if (first == 1) {
            Integer u = firA.get(0);
            for (Integer v : secA) {
                if (!connect[u][v]) return first + second;
                return first + second - 1;
            }
        } else {
            int m = roads.length;
            if (firA.size() * (firA.size() - 1) / 2 > m) return 2 * first;
            else {
                for (Integer u : firA) {
                    for (Integer v : firA) {
                        if (u != v && !connect[u][v]) return first + second;

                    }
                }
                return first + second - 1;
            }
        }
        return 0;
    }
}
