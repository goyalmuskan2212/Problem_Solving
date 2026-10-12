class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &color){
        vis[node] = 1;
        int col = color[node];
        for(auto it : adj[node]){
            if(!vis[it]){
                color[it] = !col;
                if(dfs(it, vis, adj, color) == false) return false;
            }
            else if(color[it] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> vis(V, 0);
        vector<int> color(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, vis, adj, color) == false) return false;
            }
        }
        return true;
    }
};