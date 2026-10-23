class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }
        queue<pair<pair<int, int>, int>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({{src, 0}, 0});
        while(!q.empty()){
            int u = q.front().first.first;
            int cost = q.front().first.second;
            int stops = q.front().second;
            q.pop();
            if(stops > k) continue;
            for(auto it : adj[u]){
                int v = it.first;
                int w = it.second;
                if(dist[v] > cost + w){
                    dist[v] = cost + w;
                    q.push({{v, cost+w}, stops+1});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};