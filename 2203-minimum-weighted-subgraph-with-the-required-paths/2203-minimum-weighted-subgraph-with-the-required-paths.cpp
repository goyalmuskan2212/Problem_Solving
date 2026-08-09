class Solution {
    using ll = long long;
    const ll INF = LLONG_MAX / 4;

    vector<ll> dijkstra(int n, const vector<vector<pair<int,int>>>& g, int s) {
        vector<ll> dist(n, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto [v, w] : g[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> g(n), gr(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            gr[v].push_back({u, w});
        }
        vector<ll> d1 = dijkstra(n, g, src1);
        vector<ll> d2 = dijkstra(n, g, src2);
        vector<ll> dr = dijkstra(n, gr, dest);

        ll ans = INF;
        for (int v = 0; v < n; ++v) {
            if (d1[v] == INF || d2[v] == INF || dr[v] == INF) continue;
            ans = min(ans, d1[v] + d2[v] + dr[v]);
        }
        return ans == INF ? -1 : ans;
    }
};
