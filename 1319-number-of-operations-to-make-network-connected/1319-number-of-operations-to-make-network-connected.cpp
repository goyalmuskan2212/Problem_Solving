class DisjointSet{
    public:
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] > size[ult_v]){
            size[ult_u] += size[ult_v];
            parent[ult_v] = ult_u;
        }
        else{
            size[ult_v] += size[ult_u];
            parent[ult_u] = ult_v;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraCnt = 0;
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u, v);
            }
            else extraCnt++;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }
        int ans = cnt-1;
        if(extraCnt >= ans) return ans;
        else return -1;
    }
};