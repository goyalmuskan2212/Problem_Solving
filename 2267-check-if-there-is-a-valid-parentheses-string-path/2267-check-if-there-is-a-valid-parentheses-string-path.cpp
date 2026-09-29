class Solution {
public:

    int solve(int n, int m, vector<vector<char>>& grid, int balance, vector<vector<vector<int>>>& dp) {

        if(n >= grid.size() || m >= grid[0].size()) return 0;

        if(grid[n][m] == '(') balance++;
        else balance--;

        if(balance < 0) return 0;

        if(n == grid.size() - 1 && m == grid[0].size() - 1) {
            if(balance == 0)
                return 1;
            return 0;
        }

        if(dp[n][m][balance] != -1) return dp[n][m][balance];

        if(solve(n + 1, m, grid, balance, dp) || solve(n, m + 1, grid, balance, dp)) {
            return dp[n][m][balance] = 1;
        }

        return dp[n][m][balance] = 0;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if((n + m - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n + m + 1, -1)));

        return solve(0, 0, grid, 0, dp);
    }
};