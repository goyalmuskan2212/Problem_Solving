class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int t = INT_MIN;
        while(!pq.empty()){
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            t = max(t, time);
            if(row == n-1 && col == n-1) return t;
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    pq.push({grid[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return t;
    }
};