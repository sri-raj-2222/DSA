class Solution {
public:
    int dp[101];
    int sum=0;
    int fun(vector<int> & nums,int i){
        if(i >= nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int left=fun(nums,i+2);
        int right=fun(nums,i+3);
        return dp[i] = max(left,right)+nums[i];
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return max(fun(nums,0),fun(nums,1));
    }
};