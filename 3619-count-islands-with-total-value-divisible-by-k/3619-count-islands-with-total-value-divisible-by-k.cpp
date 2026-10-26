class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, long long &sum){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        sum += grid[row][col];
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] > 0){
                dfs(nrow, ncol, vis, grid, sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] > 0){
                    long long sum = 0;
                    dfs(i, j, vis, grid, sum);
                    if(sum % k == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};