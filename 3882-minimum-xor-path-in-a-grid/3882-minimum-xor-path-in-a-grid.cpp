class Solution {
public:
    int solve(int n, int m, int temp, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(n < 0 || m < 0) return 1e9;
        temp ^= grid[n][m];
        if(n == 0 && m == 0){
            return temp;
        }
        if(dp[n][m][temp] != -1) return dp[n][m][temp];
        int right = solve(n, m-1, temp, grid, dp);
        int down = solve(n-1, m, temp, grid, dp);
        return dp[n][m][temp] = min(right, down);
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return solve(n-1, m-1, 0, grid, dp);
    }
};