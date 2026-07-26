class Solution {
public:
    void solve(queue<pair<int,int>> &q, vector<vector<int>> &heights,set<vector<int>>& nums,vector<vector<bool>>&vis){
        int n=heights.size();
        int m=heights[0].size();
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            nums.insert({r,c});
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
                    if(heights[nr][nc] >= heights[r][c]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> pq,aq;
        int n=heights.size();
        int m=heights[0].size();
        set<vector<int>> p,a;
        vector<vector<int>> ans;
        vector<vector<bool>> vis(n,vector<bool>(m));
        for(int i=0;i<m;i++){
            pq.push({0,i});
            vis[0][i]=1;
        }
        
        for(int i=0;i<n;i++){
            pq.push({i,0});
            vis[i][0]=1;
        }
        solve(pq,heights,p,vis);
        vis=vector<vector<bool>>(n,vector<bool>(m,0));
        for(int i=0;i<m;i++){
            aq.push({n-1,i});
            vis[n-1][i] = 1;
        }
        for(int i=0;i<n;i++){
            aq.push({i,m-1});
            vis[i][m-1] = 1;
        }
        solve(aq,heights,a,vis);
        for(auto arr : p){
            if(a.find(arr) != a.end()){
                ans.push_back(arr);
            }
        }
        return ans;
    }
};