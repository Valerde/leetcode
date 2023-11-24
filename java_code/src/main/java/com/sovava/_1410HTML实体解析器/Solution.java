package com.sovava._1410HTML实体解析器;

import java.util.HashMap;
import java.util.Map;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年11月23日 8:58 AM
 **/
public class Solution {
    Map<String, String> map = new HashMap<String, String>() {
        {
            put("&quot;", "\"");
            put("&apos;", "'");
            put("&amp;", "&");
            put("&gt;", ">");
            put("&lt;", "<");
            put("&frasl;", "/");
        }
    };

    public String entityParser(String text) {

        String cat = "";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < text.length(); ) {
            if (text.charAt(i) == '&') {
                int j = i + 1;
                while (j < text.length() && j - i < 6 && text.charAt(j) != ';') j++;
                cat = text.substring(i, Math.min(j + 1, text.length()));
                if (map.containsKey(cat)) {
                    sb.append(map.get(cat));
                    i = j + 1;
                    continue;
                }
            }
            sb.append(text.charAt(i));
            i++;
        }
        return sb.toString();
    }
}
