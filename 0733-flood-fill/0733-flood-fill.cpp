class Solution {
public:
    void dfs(int row, int col, int iniColor, int newColor, int dr[], int dc[], vector<vector<int>> &image){
        int n = image.size();
        int m = image[0].size();
        image[row][col] = newColor;
        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == iniColor){
                dfs(nrow, ncol, iniColor, newColor, dr, dc, image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int iniColor = image[sr][sc];
        int newColor = color;
        if(iniColor == newColor) return image;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        dfs(sr, sc, iniColor, newColor, dr, dc, image);
        return image;
    }
};