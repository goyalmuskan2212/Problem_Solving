class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        int mini = *max_element(nums.begin(), nums.end());
        for(auto it : mpp){
            int res = (mini - it.first)*it.second;
            ans += res;
        }
        return ans;
    }
};