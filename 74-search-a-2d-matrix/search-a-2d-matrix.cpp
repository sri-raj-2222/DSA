class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int idx=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][m-1] >= target){
                idx=i;
                break;
            }
        }
        // cout<<idx;
        int i=0,j=m-1;
        while(i <= j){
            int mid=(i+j)/2;
            if(matrix[idx][mid] == target) return true;
            else if(target > matrix[idx][mid]) i=mid+1;
            else j=mid-1;
        }
        return false;
    }
};