class Solution {
public:
    int dp[10000];
    int fun(int i,vector<int> &nums){
        if(i >= nums.size()) return 0;
        if(i == nums.size()-1) return 0;
        if(nums[i]==0) return 10000;
        if(dp[i] != -1) return dp[i];
        int k,mini=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            k=fun(i+j,nums);
            mini=min(k+1,mini);
        }
        return dp[i]=mini;
    }
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        memset(dp,-1,sizeof(dp));
        int ans=fun(0,nums);
        return ans;
    }
};