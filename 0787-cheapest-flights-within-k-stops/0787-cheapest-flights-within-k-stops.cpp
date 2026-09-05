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
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        while(!q.empty()){
            int price = q.front().first;
            int node = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();
            if(stops > k) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int cost = it.second;
                if(price + cost < dist[adjNode]){
                    dist[adjNode] = price + cost;
                    q.push({price + cost, {adjNode, stops+1}});
                }
            }
        }
        if(dist[dst] != 1e8) return dist[dst];
        return -1;
    }
};