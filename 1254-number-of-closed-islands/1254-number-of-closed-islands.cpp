class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
    void dfs2(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0){
                dfs2(nrow, ncol, vis, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0){
                dfs(i, 0, vis, grid);
            }
            if(grid[i][m-1] == 0){
                dfs(i, m-1, vis, grid);
            }
        }
        for(int j=0; j<m; j++){
            if(grid[0][j] == 0){
                dfs(0, j, vis, grid);
            }
            if(grid[n-1][j] == 0){
                dfs(n-1, j, vis, grid);
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(vis[i][j] == 0 && grid[i][j] == 0) {
                    cnt++;

                    dfs2(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }
};