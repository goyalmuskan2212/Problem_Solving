class Solution {
public:
    int solve(int n, int m, string s, string t, vector<vector<int>> &dp){
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(t[n-1] == s[m-1]){
            return dp[n][m] = 1 + solve(n-1, m-1, s, t, dp);
        }
        else{
            return dp[n][m] = max(solve(n-1, m, s, t, dp), solve(n, m-1, s, t, dp));
        }
    }
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int m = s.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = solve(n, m, s, t, dp);
        if(ans == m) return true;
        return false;
    }
};