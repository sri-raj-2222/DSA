class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        priority_queue<tuple<int,int,int>> q;
        q.push({health-grid[0][0],0,0});
        dist[0][0] = health - grid[0][0];
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        // cout<<dist[0][0];
        while(!q.empty()){
            auto [h,r,c] = q.top();
            q.pop();
            if(r == n-1 && c == m-1) return true;
            if(h <= 0) continue;
            for(int i=0;i<4;i++){
                int nr=row[i]+r;
                int nc=col[i]+c;
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int nh=h-grid[nr][nc];
                    if(nh > dist[nr][nc]){
                        dist[nr][nc] = nh;
                        q.push({nh,nr,nc});
                    }
                }
            }
        }
        return false;
    }
};