package java;

import java.util.*;
import java.util.stream.Collectors;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月13日 16:06
 **/
public class _49 {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> m = new HashMap<>();

        for (String item : strs) {
            String temp = item;
            char[] chars = item.toCharArray();
            Arrays.sort(chars);
//            System.out.println(chars.toString());
            String key = new String(chars);
            List<String> orDefault = m.getOrDefault(key, new ArrayList<>());
            orDefault.add(temp);
            m.put(key,orDefault);
        }

        List<List<String>> res = new ArrayList<>(m.values());


        List<List<String>> lists = Collections.synchronizedList(res);


        return res;
    }
}
