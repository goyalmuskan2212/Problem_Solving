class Solution {
public:
    int solve(int n, vector<int> &nums, vector<int> &dp){
        if(n == 0) return nums[0];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int incl = nums[n];
        if(n >= 2){
            incl += solve(n-2, nums, dp);
        }
        int excl = solve(n-1, nums, dp);
        return dp[n] = max(incl, excl);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0; i<n; i++){
            if(i != n-1) temp1.push_back(nums[i]);
            if(i != 0) temp2.push_back(nums[i]);
        }
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int first = solve(n-2, temp1, dp1);
        int second = solve(n-2, temp2, dp2);
        return max(first, second);
    }
};
