class Solution {
public:
    void solve(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &image, int dr[], int dc[], int iniColor, int newColor){
        int n = image.size();
        int m = image[0].size();
        image[row][col] = newColor;
        vis[row][col] = 1;
        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && image[nrow][ncol] == iniColor && vis[nrow][ncol] == 0){
                solve(nrow, ncol, vis, image, dr, dc, iniColor, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int iniColor = image[sr][sc];
        int newColor = color;
        if(iniColor == newColor) return image;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        solve(sr, sc, vis, image, dr, dc, iniColor, newColor);
        return image;
    }
};