class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> ans(m, vector<char>(n, '#'));
        int i = 0;
        int j = 0;
        while(j <= n-1){
            ans[i][j] = '.';
            j = j + 1;
        }
        while(i <= m-1){
            ans[i][n-1] = '.';
            i = i+1;
        }
        vector<string> res;
        for(int i=0; i<m; i++){
            string s = "";
            for(int j=0; j<n; j++){
                s += ans[i][j];
            }
            res.push_back(s);
        }
        return res;
    }
};