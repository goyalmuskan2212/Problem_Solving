class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<n-1; i++){
            int orgNext = nums[i] + 1;
            int nxt = nums[i+1];
            while(orgNext < nxt){
                ans.push_back(orgNext);
                orgNext++;
            }
        }
        return ans;
    }
};