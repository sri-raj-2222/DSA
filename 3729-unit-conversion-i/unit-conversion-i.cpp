class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& grid) {
         int maxNode = 0;
        for (auto &i : grid) {
            maxNode = max({maxNode, i[0], i[1]});
        }
        int n = maxNode + 1;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &i : grid){
            adj[i[0]].push_back({i[2],i[1]});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        >pq;
        pq.push({1,0});
        dist[0]=1;
        while(!pq.empty()){
           auto [d,node]=pq.top();
           pq.pop();
           if(d > dist[node]) continue;
           for(auto [cd,v] : adj[node]){
                int nd=(cd*d)%(1000000007);
                if(nd < dist[v]){
                    dist[v]=nd;
                    pq.push({nd,v});
                }
           }
        }
        return dist;
    }
};