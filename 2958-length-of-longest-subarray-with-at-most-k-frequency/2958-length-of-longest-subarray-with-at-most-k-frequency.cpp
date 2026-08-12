class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int max_len = 0;
        unordered_map<int, int> mpp;
        while(j < n){
            if(mpp.find(nums[j]) == mpp.end() || mpp[nums[j]] < k){
                mpp[nums[j]]++;
                max_len = max(max_len, j-i+1);
                j++;
            }
            else{
                while(mpp[nums[j]] >= k){
                    if(mpp[nums[i]] > 1){
                        mpp[nums[i]]--;
                        i++;
                    }
                    else{
                        mpp.erase(nums[i]);
                        i++;
                    }
                }
            }
        }
        return max_len;
    }
};