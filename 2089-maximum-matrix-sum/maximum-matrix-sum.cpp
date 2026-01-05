class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg=0;
        long long sum=0;
        long long mini=LLONG_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                mini=min(mini,llabs(matrix[i][j]));
                sum+=llabs(matrix[i][j]);
                if(matrix[i][j]<0) neg++;
            }
        }
        if(neg%2!=0){
            sum-=(2*mini);
        }
        return sum;

    }
};