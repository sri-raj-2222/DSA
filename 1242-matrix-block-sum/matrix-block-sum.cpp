class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> pre(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                sum += mat[i][j];
                pre[i][j] = sum;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int row1 = i-k < 0 ? 0 : i-k;
                int row2 = i+k >= n ? n-1 : i+k;
                int col1 = j-k < 0 ? 0 : j-k;
                int col2 = j+k >= m ? m-1 : j+k;
                int sum=0;
                for(int p = row1; p <= row2 ;p++){
                    if(col1 == 0) sum += pre[p][col2];
                    else sum += pre[p][col2] - pre[p][col1-1];
                }
                mat[i][j] = sum;
            }
        }
        return mat;
    }
};