class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        if(n == 0) return 0;
        if(n == 1 && img1[0][0] == img2[0][0]) return img1[0][0];
        int maxi = 0;
        for (int dr = -(n-1); dr <= n-1; dr++) {
            for (int dc = -(n-1); dc <= n-1; dc++) {
                int cnt = 0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        int row = i - dr;
                        int col = j - dc;
                        if(row>=0 && row<n && col>=0 && col<n){
                            if(img1[row][col] == 1 && img2[i][j] == 1){
                                cnt++;
                            }
                        }
                    }
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};
