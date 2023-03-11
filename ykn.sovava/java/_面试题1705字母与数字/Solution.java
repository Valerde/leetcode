package java._面试题1705字母与数字;

import java.util.HashMap;
import java.util.Map;

/**
 * Description: TODO
 * 给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。
 * <p>
 * 返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。
 * <p>
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/find-longest-subarray-lcci
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author: ykn
 * @date: 2023年03月11日 14:48
 **/
public class Solution {
    public String[] findLongestSubarray(String[] array) {
        int maxLength = 0;
        int startIndex = -1;
        int end = 0;
        int sum = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0,-1);
        for (int i = 0; i < array.length; i++) {
            if (Character.isLetter(array[i].charAt(0))) {
                sum++;
            } else {
                sum--;
            }
            if (map.containsKey(sum)) {
                int temp = map.get(sum);
                if (maxLength < i - temp) {
                    maxLength = i - temp;
                    startIndex = temp+1;
                }


            } else {
                map.put(sum, i);
            }
        }
        if (maxLength == 0) {
            return new String[0];
        }
        String[] res = new String[maxLength];
        System.arraycopy(array, startIndex, res, 0, maxLength);
        return res;
    }
}
