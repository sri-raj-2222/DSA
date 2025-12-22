class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
        vector<vector<int>> adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<res.size();i++){
            vis[res[i]]=2;
        }
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(vis[node]==2) continue;
            for(int v : adj[node]){
                if(vis[v]==2) continue;
                else if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==1) cnt++;
        }
        return cnt;
    }
};