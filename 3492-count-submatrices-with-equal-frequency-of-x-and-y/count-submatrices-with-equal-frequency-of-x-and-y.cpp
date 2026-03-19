class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        vector<vector<int>> nums (n,vector<int>(m));
        vector<vector<int>> xCnt (n,vector<int>(m));
        for(int i = 0 ; i < n ; i++){
            for(int  j = 0 ; j < m ; j++){
                if(grid[i][j] == 'X'){
                    nums[i][j] = 1;
                    xCnt[i][j] = 1;
                }
                else if(grid[i][j] == 'Y'){
                    nums[i][j] = -1;
                    xCnt[i][j] = 0;
                }
                else{
                    nums[i][j] = 0;
                    xCnt[i][j] = 0;
                }
                if(i > 0){
                    nums[i][j] += nums[i-1][j]; xCnt[i][j] += xCnt[i-1][j];
                }
                if(j > 0){
                    nums[i][j] += nums[i][j-1]; xCnt[i][j] += xCnt[i][j-1];
                }
                if(i > 0 && j > 0){
                    nums[i][j] -= nums[i-1][j-1]; xCnt[i][j] -= xCnt[i-1][j-1];
                }
                if(nums[i][j] ==  0 && xCnt[i][j] > 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};