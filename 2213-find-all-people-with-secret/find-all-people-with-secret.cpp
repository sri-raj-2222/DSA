class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int f) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &i : meetings){
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
        pq.push({0,f});
        time[0]=0;
        time[f]=0;
        while(!pq.empty()){
            auto [t,u]=pq.top();
            pq.pop();
            if(t > time[u]) continue;
            for(auto &[nt,v] : adj[u]){
                if(nt < t) continue;
                int nd=max(t,nt);
                if(time[v] > nd){
                    time[v]=nd;
                    pq.push({nd,v});
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(time[i]!=INT_MAX) ans.push_back(i);
        }
        return ans;
    }
};