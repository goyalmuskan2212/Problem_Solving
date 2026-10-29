class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bit=0; bit<=31; bit++){
            int zeros = 0;
            int ones = 0;
            for(int i=0; i<nums.size(); i++){
                //if it is set bit then increase ones by 1.
                if(nums[i] & (1 << bit)){
                    ones++;
                }
                else{
                    zeros++;
                }
            }
            if(ones%3 != 0){
                ans  = (ans | (1<<bit));
            }
        }
        return ans;
    }
};