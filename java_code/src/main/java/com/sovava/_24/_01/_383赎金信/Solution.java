package com.sovava._24._01._383赎金信;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月07日 0:18
 **/
public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if(ransomNote.length()>magazine.length())return false;
        char[] chars = magazine.toCharArray();
        int[] ch = new int[26];
        for (char aChar : chars) {
            ch[aChar-'a'] ++;
        }

        char[] chars1 = ransomNote.toCharArray();
        for (char c : chars1) {
            ch[c-'a']--;
            if(ch[c-'a']<0){
                return false;
            }
        }
        return true;
    }
}
