class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool> vis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                vis[adj[i][j]]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0) ans.push_back(i);
        }
        return ans;
    }
};