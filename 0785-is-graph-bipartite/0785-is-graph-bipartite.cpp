class Solution {
public:
    bool dfs(int node, int col, vector<int> &color, vector<int> adj[]){
        color[node] = col;
        for(auto adjNode : adj[node]){
            if(color[adjNode] == col) return false;
            if(color[adjNode] == -1){
                if(dfs(adjNode, !col, color, adj) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            int size = graph[i].size();
            for(int j=0; j<size; j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> color(n, -1);
        int col = 0;
        for(int i=0 ;i<n; i++){
            if(color[i] == -1){
                if(dfs(i, col, color, adj) == false) return false;
            }
        }
        return true;
    }
};