package com.sovava._23._12._面试题1011峰与谷;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年12月30日 0:16
 **/
public class Solution {
    public void wiggleSort(int[] nums) {
        int len = nums.length;
        if(len <2)return ;
        int tmp = 0;
        if(nums[0]>nums[1]){
            tmp = nums[0];
            nums[0] = nums[1];
            nums[1] = tmp;
        }
        for (int i = 2; i < nums.length; i++) {
            if(i%2 == 0){
                //峰
                if(nums[i]>nums[i-1]){
                    tmp = nums[i];
                    nums[i] = nums[i-1];
                    nums[i] = tmp;
                }
            }else{
                //谷
                if(nums[i]<nums[i-1]){
                    tmp = nums[i];
                    nums[i] = nums[i-1];
                    nums[i] = tmp;
                }
            }
        }
    }


}
