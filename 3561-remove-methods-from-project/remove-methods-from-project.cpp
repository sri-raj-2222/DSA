class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& mat) {
        vector<vector<int>> grid(n);
        for(auto i : mat){
            grid[i[0]].push_back(i[1]);
        }
        vector<int> vis(n);
        queue<int> q,pq;
        q.push(k);
        vis[k] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : grid[u]){
                if(vis[v] == 0){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        for(auto i : mat){
            grid[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                pq.push(i);
                vis[i] = 2;
            }
        }
        while(!pq.empty()){
            int u = pq.front();
            pq.pop();
            for(int v : grid[u]){
                if(vis[v] == 1 || vis[v] == 0){
                    vis[v] = 2;
                    pq.push(v);
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i] == 2) ans.push_back(i);
        }
        return ans;
    }
};