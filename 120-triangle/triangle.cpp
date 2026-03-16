class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int> dp=nums[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=nums[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};