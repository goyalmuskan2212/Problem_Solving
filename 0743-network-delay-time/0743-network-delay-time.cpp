class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int v = it.first;
                int d = it.second;
                if(dis + d < dist[v]){
                    dist[v] = dis + d;
                    pq.push({dis+d, v});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};