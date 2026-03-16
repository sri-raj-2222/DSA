class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        vector<int> dp(n);
        dp[n-1]=nums[n-1];
        int mini=INT_MIN;
        int ans=0;
        for(int i=n-2;i>=1;i--){
            mini=max(mini,dp[i+1]-nums[i]);
            dp[i]=max(nums[i],dp[i+1]);
            if(nums[i-1] > nums[i]){
                if(mini > 0) ans+=mini;
                mini=INT_MIN;
                dp[i]=nums[i];
            }
            
        }
        if(dp[1]-nums[0] > 0)ans+=dp[1]-nums[0];
        return ans;
    }
};