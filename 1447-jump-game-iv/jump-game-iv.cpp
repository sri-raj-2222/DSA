class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> mpp;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            mpp[arr[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        vector<int> vis(n);
        q.push({0,0});
        vis[0] = 1;
        while(!q.empty()){
            auto [u,d] = q.front();
            q.pop();
            if(u == n-1) return d;
            if(u-1 >= 0 && !vis[u-1]){
                q.push({u-1,d+1});
                vis[u-1]=1;
            }
            if(u+1 < n && !vis[u+1]){
                q.push({u+1,d+1});
                vis[u+1]=1;
            }
            for(int v : mpp[arr[u]]){
                if(!vis[v]){
                    q.push({v,d+1});
                    vis[v]=1;
                }
            }
            mpp[arr[u]].clear();
        }
        return -1;
    }
};