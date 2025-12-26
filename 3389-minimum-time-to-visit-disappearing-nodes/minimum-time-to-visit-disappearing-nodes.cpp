class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& dis) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back({i[2],i[1]});
            adj[i[1]].push_back({i[2],i[0]});
        }
        vector<int> time(n,INT_MAX);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >pq;
        pq.push({0,0});
        time[0]=0;
        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();
            if(t > dis[node] || t > time[node]) continue;
            for(auto [ct,v] : adj[node]){
                int nt=ct+t;
                if(dis[v] > nt){
                    if(time[v] > nt){
                        time[v]=nt;
                        pq.push({nt,v});
                    }
                }
            }
        }
        for(int i=0;i<n;i++) if(time[i]==INT_MAX) time[i]=-1;
        return time;
    }
};