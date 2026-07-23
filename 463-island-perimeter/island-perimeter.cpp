class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m));
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                    ans=4;
                    flag=1;
                    break;
                }
            }
            if(flag == 1) break;
        }
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    if(!vis[nr][nc]){
                        ans+=4;
                        q.push({nr,nc});
                        vis[nr][nc] = 1;
                    }
                    ans--;
                }

            }
        }
        return ans;
    }
};