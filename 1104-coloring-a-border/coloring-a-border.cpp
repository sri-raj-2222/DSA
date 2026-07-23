class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans = grid;
        vector<vector<bool>> vis(n,vector<bool>(m));
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;
        int og = grid[row][col];
        int ro[4] = {0,0,-1,1};
        int co[4] = {-1,1,0,0};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = r+ro[i];
                int nc = c+co[i];
                if(nr < 0 || nc < 0 || nr > n-1 || nc > m-1){
                    ans[r][c] = color;
                    continue;
                }
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
                    if(grid[nr][nc] != og){
                        ans[r][c] = color;
                    }
                    if(grid[nr][nc] == og){
                        q.push({nr,nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        return ans;
    }
};