class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<int> dp=nums;
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=n-2;i>=0;i--){
            ans=max(ans,dp[i+1]-nums[i]); 
            dp[i]=max(nums[i],dp[i+1]);
        }
        if(ans < 0) return 0;
        return ans;
    }
};