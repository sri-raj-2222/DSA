class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int,int,int>>> adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back({i[2],i[1],1});
            adj[i[1]].push_back({i[2],i[0],0});
        }
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        >pq;
        vector<int> dist(n,INT_MAX);
        pq.push({0,0,1});
        dist[0]=0;
        while(!pq.empty()){
            auto [d,node,f]=pq.top();
            pq.pop();
            if(d > dist[node]) continue;
            for(auto [nd,v,nf] : adj[node]){
                int next;
                if(nf==0) next=d+(2*nd);
                else next=d+nd;
                if(dist[v] > next){
                    dist[v]=next;
                    pq.push({next,v,nf});
                }
            }
        }
        if(dist[n-1]==INT_MAX) return -1;
        else return dist[n-1];
    }
};