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
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = grid[0][0];
        // First column
        for(int i = 1; i < n; i++) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        // First row
        for(int j = 1; j < m; j++) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                int ans = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = ans;
            }
        }
        return dp[n-1][m-1];
    }
};