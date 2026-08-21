class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = solve(n-1, dp) + solve(n-2, dp);
        return dp[n] = ans;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        int prev1 = 1;
        int prev2 = 1;
        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};