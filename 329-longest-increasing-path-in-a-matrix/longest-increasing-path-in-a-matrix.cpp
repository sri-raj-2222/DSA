class Solution {
public:
    int ans=-1;
    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dist){
        if(dist[i][j] != -1) return dist[i][j];
        int n=grid.size();
        int m=grid[0].size();
        int row[4] = {0,0,-1,1};
        int col[4] = {-1,1,0,0};
        dist[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+row[k];
            int nc=j+col[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                if(grid[nr][nc] > grid[i][j]){
                    dist[i][j] = max(dist[i][j] , 1+solve(nr,nc,grid,dist));
                }
            }
        }
        return dist[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,solve(i,j,grid,dist));
            }
        }
        return ans;

    }
};