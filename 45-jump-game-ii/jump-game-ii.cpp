class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int> dp(n,INT_MAX);
        dp[n-1]=0;
        if(dp[n-2] > 0) dp[n-2]=1;
        else dp[n-2] = INT_MAX;
        for(int i=n-3;i>=0;i--){
            if(nums[i] == 0){
                dp[i]=INT_MAX;
            }
            int mini=INT_MAX;
            for(int j=1;j<=nums[i];j++){
                if(j+i < n) mini=min(mini,dp[j+i]);
            }
            if(mini != INT_MAX) dp[i]=1+mini;
            else dp[i]=INT_MAX;
        }
        return dp[0];
    }
};