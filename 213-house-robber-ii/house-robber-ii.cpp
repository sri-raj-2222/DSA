class Solution {
public:
int dp[10001];
    int dfs(vector<int> &nums,int i,int end){
        int n=nums.size();
        if(i > end) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] +  dfs(nums , i + 2 ,end);
        int skip = dfs( nums , i + 1 ,end);
        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int case1 = dfs(nums,0,n-2);
        memset(dp,-1,sizeof(dp));
        int case2 = dfs(nums,1,n-1);
        return max(case1,case2);
    }
};