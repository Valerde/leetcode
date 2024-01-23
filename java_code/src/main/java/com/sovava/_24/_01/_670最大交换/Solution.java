package com.sovava._24._01._670最大交换;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2024年01月22日 0:12
 **/
public class Solution {

    public int maximumSwap(int num) {
        if (num == 0)
            return 0;
        char[] chars = String.valueOf(num).toCharArray();
        int[] maxIndex = new int[chars.length];
        int max = chars.length - 1;
        //倒过来寻找，当前位置往右，最大的数的下标
        for (int j = chars.length - 1; j >= 0; j--) {
            if (chars[j] - '0' > chars[max] - '0') {
                max = j;
            }
            maxIndex[j] = max;
        }
        //正序遍历，找到第一个不是最大的数，将该位置和右边最大数换位置
        for (int i = 0; i < chars.length; i++) {
            int iValue = chars[i] - '0';
            int maxValue = chars[maxIndex[i]] - '0';
            if (maxValue != iValue) {
                chars[i] = (char) (maxValue + '0');
                chars[maxIndex[i]] = (char) (iValue + '0');
                break;
            }
        }
        return Integer.parseInt(new String(chars));
    }


}
