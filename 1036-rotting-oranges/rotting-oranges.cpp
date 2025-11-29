class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid,int n,int m,int min){
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j]==0 || (grid[i][j]!=1 && grid[i][j]<min)) return;
        grid[i][j]=min;
        dfs(i-1,j,grid,n,m,min+1);
        dfs(i+1,j,grid,n,m,min+1);
        dfs(i,j-1,grid,n,m,min+1);
        dfs(i,j+1,grid,n,m,min+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    dfs(i,j,grid,n,m,2);
                }
            }
        }
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
                ans=max(ans,grid[i][j]);
            }
        }
        return ans-2;

    }
};