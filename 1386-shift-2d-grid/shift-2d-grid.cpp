class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> mat = grid;
        int n=grid.size();
        int m=grid[0].size();
        k=k%(n*m);
        while(k--){
            for(int i=0;i<n;i++){
                for(int j=0;j<m-1;j++){
                    grid[i][j+1] = mat[i][j];
                }
            }
            for(int i=0;i<n-1;i++){
                grid[i+1][0] = mat[i][m-1];
            }
            grid[0][0] = mat[n-1][m-1]; 
            mat = grid;
        }
        return grid;
    }
};