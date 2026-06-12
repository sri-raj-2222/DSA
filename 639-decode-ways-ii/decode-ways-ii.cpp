class Solution {
public:
const int MOD = 1e9+7;
vector<long long> dp;
    long long solve(string &s , int i){
        int n = s.size();
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        long long left = 0 , right = 0;
        if(s[i] == '0') return 0;
        if(s[i] != '*') left += (solve(s, i+1)) % MOD;
        if(s[i] == '*'){
            left += (9LL * solve(s , i+1)) % MOD;
        }
        if(i+1 < n && s[i] != '*' && s[i+1] != '*'){
            int num = (s[i]-'0')*10 + (s[i+1]-'0');
            if(num >= 10 && num <= 26)
                right += (solve(s, i+2)) % MOD;
        }
        if(i+1 < n && s[i] == '1' && s[i+1] == '*'){
            right += (9LL * solve(s , i+2)) % MOD;
        }
        if(i+1 < n && s[i] == '2' && s[i+1] == '*'){
            right +=  (6LL * solve(s , i+2)) % MOD;
        }
        if(i+1 < n && s[i] == '*' && s[i+1] == '*'){
            right += (15LL * solve(s , i+2)) % MOD;
        }
        if(i+1 < n && s[i] == '*' && s[i+1] <= '6' && s[i+1] != '*'){
            right += (2LL * solve(s, i+2)) % MOD;
        }
        if(i+1 < n && s[i] == '*' && s[i+1] >= '7' && s[i+1] <= '9' && s[i+1] != '*'){
            right += (solve(s, i+2)) % MOD;
        }
        return dp[i] = (left + right) % MOD;
    }
    int numDecodings(string s) {
        dp.assign(s.size() , -1);
        return solve(s,0);
    }
};