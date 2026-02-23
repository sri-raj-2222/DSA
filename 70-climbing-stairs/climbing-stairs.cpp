class Solution {
public:
int dp[46];
    int dfs(int n){
        if(n <= 0) return 1;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = dfs(n-1)+dfs(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
       return dfs(n);
    }
};