class Solution {
public:
    int dp[10001];
    int fun(int amount,vector<int> &arr){
        if(amount == 0 ) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int k,mini=INT_MAX;
        for(int i=0;i<arr.size();i++){
            k=fun(amount-arr[i],arr);
            if(k!=INT_MAX){
                mini=min(mini,k+1);
            }
        }
        return dp[amount] = mini;
    }
    int coinChange(vector<int>& arr, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans=fun(amount,arr);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};