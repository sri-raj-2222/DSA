class Solution {
public:
vector<int> dp;
    int solve(string &s ,int i){
        int n = s.size();
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return 0;
        int res = solve(s , i+1);
        if(i+1 < n && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')){
            res += solve(s,i+2);
        }
        return dp[i] = res;
    }
    int numDecodings(string s) {
        dp.assign(s.size(),-1);
        return solve(s,0);
    }
};