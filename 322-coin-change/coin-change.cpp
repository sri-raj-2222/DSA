class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<amount+1;i++){
            int mini=INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(i-coins[j] >=0) mini=min(mini,dp[i-coins[j]]);            
            }
            if(mini != INT_MAX) dp[i]=1+mini;
            else dp[i]=mini;
        }
        return (dp[amount]!=INT_MAX) ? dp[amount] : -1;
    }
};