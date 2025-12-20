class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& nums, int s, int e) {
        vector<vector<pair<double,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=nums[i];
            adj[u].push_back({p,v});
            adj[v].push_back({p,u});
        }
        vector<double> dist(n,INT_MIN);
        priority_queue<
            pair<double,int>,
            vector<pair<double,int>>,
            less<pair<double,int>>
        >pq;
        pq.push({1,s});
        while(!pq.empty()){
            auto [p,node]=pq.top();
            pq.pop();
            for(auto [np,v] : adj[node]){
                if(np*p > dist[v]){
                    dist[v]=np*p;
                    pq.push({np*p,v});
                }
            }
        }
        if(dist[n-1]==INT_MIN) return 0;
        return dist[e];
    }
};