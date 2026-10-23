class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        q.push({0, {0, 0}});
        while(!q.empty()){
            int row = q.top().second.first;
            int col = q.top().second.second;
            int dis = q.top().first;
            q.pop();
            if(dis > dist[row][col]) continue;
            if(row == n-1 && col == m-1) return dis;
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort = max(dis, abs(heights[nrow][ncol] - heights[row][col]));
                    if(newEffort < dist[nrow][ncol]){
                        // Update distance
                        // Push into priority queue
                        dist[nrow][ncol] = newEffort;
                        q.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};