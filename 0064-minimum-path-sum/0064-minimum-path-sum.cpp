class Solution {
public:
    int solve(int n, int m, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(n < 0 || m < 0) return INT_MAX;
        if(n == 0 && m == 0) return grid[0][0];
        if(dp[n][m] != -1) return dp[n][m];
        int ans = grid[n][m] + min(solve(n-1, m, grid, dp), solve(n, m-1, grid, dp));
        return dp[n][m] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = solve(n-1, m-1, grid, dp);
        return ans;
    }
};