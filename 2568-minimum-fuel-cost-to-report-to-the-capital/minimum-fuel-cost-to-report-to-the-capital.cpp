class Solution {
public:
    long long dfs(int u,vector<vector<int>> &adj,vector<bool> &vis,long long &ans,int seats){
        vis[u]=1;
        long long cnt=1;
        for(int v : adj[u]){
            if(!vis[v]){
                long long ch=dfs(v,adj,vis,ans,seats);
                ans+=(ch+seats-1)/seats;
                cnt+=ch;
            }
        }
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<vector<int>> adj(n+1);
        for(auto &i : roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n+1,0);
        long long ans=0;
        dfs(0,adj,vis,ans,seats);
        return ans;
    }
};