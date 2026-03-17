class Solution {
public:
vector<vector<int>> dp;
    int dfs(int i,int j,vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i == n-1 && j ==  m-1) return grid[i][j];
        if(i >= n || j >= m) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int down=dfs(i+1,j,grid);
        int right=dfs(i,j+1,grid);
        return dp[i][j] = grid[i][j]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return dfs(0,0,grid);
    }
};