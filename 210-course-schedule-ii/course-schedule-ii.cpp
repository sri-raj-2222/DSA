class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> indeg(n);
        for(int i=0;i<n;i++){
            for(auto v : adj[i]){
                indeg[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(auto v : adj[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size() == n) return ans;
            else return {};
    }
};