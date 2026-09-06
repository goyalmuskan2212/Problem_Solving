class Solution {
public:
    int solve(int n, int m, string s1, string s2, vector<vector<int>> &dp){
        if(m == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s1[n-1] == s2[m-1]){
            return dp[n][m] = solve(n-1, m-1, s1, s2, dp) + solve(n-1, m, s1, s2, dp);
        }
        else{
            return dp[n][m] = solve(n-1, m, s1, s2, dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, s, t, dp);
    }
};