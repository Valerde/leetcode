class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int ma = 0;
        for(int i = 0; i<nums.size();i++){
            if(m.find(nums[i])!=m.end())continue;
            if(m.find(nums[i]-1)==m.end()&&m.find(nums[i]+1)==m.end()){
                 m.emplace(nums[i],1);
                 ma = max(1,ma);
            }else if(m.find(nums[i]-1)!=m.end()&&m.find(nums[i]+1)!=m.end()){
                int temp1 = m[nums[i]-1];
                int temp2 = m[nums[i]+1];
                for(int j = 1;j<=temp1;j++){
                    m[nums[i]-j] = temp1+temp2+1;
                }
                for(int j = 1;j<=temp2;j++){
                    m[nums[i]+j] = temp1+temp2+1;
                }
                 m.emplace(nums[i],temp1+temp2+1);
                ma = max(temp1+temp2+1,ma);
            }else if(m.find(nums[i]-1)!=m.end()){
                int temp = m[nums[i]-1];
                for(int j = 1;j<=temp;j++){
                    m[nums[i]-j] = temp+1;
                }

                m.emplace(nums[i],temp+1);
                ma = max(temp+1,ma);
            }else if(m.find(nums[i]+1)!=m.end()){
                int temp = m[nums[i]+1];
                for(int j = 1;j<=temp;j++){
                    m[nums[i]+j] = temp+1;
                }

                m.emplace(nums[i],temp+1);
                ma = max(temp+1,ma);
            }
        }
        return ma;
    }
};
