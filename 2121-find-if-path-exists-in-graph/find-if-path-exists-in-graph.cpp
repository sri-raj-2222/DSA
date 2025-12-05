class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        if(src==dest) return true;
        vector<vector<int>> adj(n);
        for(auto i :edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        priority_queue<
        int,
        vector<int>,
        greater<int>
        > q;
        vector<bool> vis(n,0);
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int u=q.top();
            q.pop();
            for(int v : adj[u]){
                if(vis[v]==0){
                    vis[v]=1;
                    q.push(v);
                }
                if(v == dest) return true;
            }
        }
        return false;
    }
};