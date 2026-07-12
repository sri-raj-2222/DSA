class Solution {
public:
    vector<vector<string>>vct;
    void solve(int index,vector<string>&path,string& s,vector<vector<bool>> &dp){
        if(index==s.size()){
            vct.push_back(path);
            return ;
        }
        for(int i=index;i<s.length();i++){
            if(dp[index][i]){
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,path,s,dp);
                 path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i] == s[j]){
                    if(j-i <= 1){
                        dp[i][j] = 1; 
                    }
                    else dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        vector<string>path;
        solve(0,path,s,dp);
        return vct;
    }
};