class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int idx1 = 0,idx2 =0;
        while(idx1<len){
            while(idx2<len&&nums[idx2]!=0)idx2++;
            idx1 = idx2;
            while(idx1<len&&nums[idx1]==0)idx1++;
            
            if(idx1==len) break;
           
            int temp = nums[idx1];
            nums[idx1] = nums[idx2];
            nums[idx2] = temp;
            
            
        }
    }
};
