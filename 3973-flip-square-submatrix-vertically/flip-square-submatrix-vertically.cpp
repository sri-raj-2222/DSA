class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = y ; i < y + k ; i++){
            int left = x, right = x + k - 1;
            while(left < right){
                swap(grid[left][i],grid[right][i]);
                left++;
                right--;
            }
        }
        return grid;
    }
};