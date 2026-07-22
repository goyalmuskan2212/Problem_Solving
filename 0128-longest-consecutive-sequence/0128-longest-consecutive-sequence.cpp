class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n == 0) return 0;
        int maxi = 1;
        int len = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                len++;
                maxi = max(maxi, len);
            }
            else if(nums[i] == nums[i-1]){
                continue;
            }
            else{
                len = 1;
            }
        }
        return maxi;
    }
};