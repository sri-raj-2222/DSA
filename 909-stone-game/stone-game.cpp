class Solution {
public:
    int check(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if (i == j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int pick=nums[i]+min(check(nums,i+2,j,dp),check(nums,i+1,j-1,dp));
        int npick=nums[j]+min(check(nums,i+1,j-1,dp),check(nums,i,j-2,dp));
        return dp[i][j]=max(pick,npick);
    }
    bool stoneGame(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int p1= check(nums,0,nums.size()-1,dp);
        int total=0;
        for(auto i : nums) total+=i;
        int p2=total-p1;
        return p1>=p2;
    }
};