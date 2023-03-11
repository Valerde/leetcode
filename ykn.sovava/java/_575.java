package java;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月11日 19:12
 **/
public class _575 {
    public int distributeCandies(int[] candyType) {
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < candyType.length; i++) {
            s.add(candyType[i]);
        }
        return candyType.length / 2 > s.size() ? s.size() : candyType.length;
    }
}
