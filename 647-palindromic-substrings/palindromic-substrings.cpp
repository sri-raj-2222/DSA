class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i] == s[j]){
                    if(j-i <= 1){
                        dp[i][j] = true;
                    }
                    else dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]) ans++;
            }
        }
        return ans;
    }
};