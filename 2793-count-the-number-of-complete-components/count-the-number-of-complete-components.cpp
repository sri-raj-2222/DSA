class Solution {
public:
    int c=0,e=0;
    void dfs(vector<vector<int>> &adj,int par,vector<int> &vis,int i){
        vis[i] = 1;
        c++;
        e+=adj[i].size();
        for(int v : adj[i]){
            if(!vis[v]){
                dfs(adj,i,vis,v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        int ans=0;
        // int c=0,e=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,-1,vis,i);
                int a = (c*(c-1))/2;
                if(a == e/2) ans++;
                c=0,e=0;
            }
        }
        return ans;
    }
};