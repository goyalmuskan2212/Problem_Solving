class Solution {
public:
    int solve(int n, int m, string s1, string s2, vector<vector<int>> &dp){
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s1[n-1] == s2[m-1]){
            return dp[n][m] = 1 + solve(n-1, m-1, s1, s2, dp);
        }
        else{
            return dp[n][m] = max(solve(n-1, m, s1, s2, dp), solve(n, m-1, s1, s2, dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string newS = s;
        reverse(newS.begin(), newS.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == newS[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};