package com.sovava._24._01._2085统计出现过一次的公共字符串;

import java.util.HashMap;
import java.util.Map;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月12日 0:34
 **/
public class Solution {
    public int countWords(String[] words1, String[] words2) {
        Map<String, Integer> m1 = new HashMap<>(), m2 = new HashMap<>();
        for (String s : words1) {
            m1.put(s, m1.getOrDefault(s, 0) + 1);
        }

        for (String s : words2) {
            m2.put(s, m2.getOrDefault(s, 0) + 1);
        }
        int res = 0;
        if(m1.size()<m2.size()){
            for (Map.Entry<String, Integer> entry : m1.entrySet()) {
                if(entry.getValue() == 1 && m2.containsKey(entry.getKey())&& m2.get(entry.getKey()) == 1){
                    res++;
                }
            }
        }
        return res;
    }
}
