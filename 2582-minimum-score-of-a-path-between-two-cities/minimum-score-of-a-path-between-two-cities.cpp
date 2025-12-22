class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        int mini=INT_MAX;
        for(auto &i :roads){
            adj[i[0]].push_back({i[2],i[1]});
            adj[i[1]].push_back({i[2],i[0]});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >pq;
        pq.push({INT_MAX,1});
        dist[1]=INT_MAX;
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            for(auto [nd,v] : adj[node]){
                int m=min(d,nd);
                if(dist[v] > m){
                    dist[v]=m;
                    pq.push({m,v});
                }
            }
        }
        return *min_element(dist.begin(),dist.end());
    }
};