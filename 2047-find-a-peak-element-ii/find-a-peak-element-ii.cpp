class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0;
        int high = rows - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            int col = -1;
            int max = -1;

            for(int i = 0; i < cols; i++) {
                if(mat[mid][i] > max) {
                    max = mat[mid][i];
                    col = i;
                }
            }

            int top = -1;
            int bottom = -1;

            top = mid - 1 >= 0? mat[mid - 1][col]: top;
            bottom = mid + 1 < rows? mat[mid + 1][col]: bottom;

            if(top < max && max > bottom) {
                return{mid, col};
            } 
            else if(top < max && max < bottom) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return {-1,-1};
    }
};