class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if(n==1) return 0;
        vector<vector<tuple<int,int,int>>> adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back({i[1],i[2],i[3]});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >pq;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            for(auto [v,ns,ne] : adj[u]){
                int nd=max(ns,d)+1;
                if(ne<d) continue;
                if(dist[v] > nd){
                    dist[v]=nd;
                    pq.push({nd,v});
                }
            }
        }
        if(dist[n-1]==INT_MAX) return -1;
        else return dist[n-1];
    }
};