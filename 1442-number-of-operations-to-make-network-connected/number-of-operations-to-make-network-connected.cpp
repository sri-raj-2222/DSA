class Solution {
public:
    void dfs(int u,vector<vector<int>> &adj,vector<bool> &vis){
        vis[u]=1;
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& grid) {
        if(grid.size() < n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto &i : grid){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt-1;

    }
};