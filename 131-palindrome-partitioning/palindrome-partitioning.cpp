class Solution {
public:
    vector<vector<string>>vct;
    vector<vector<int>> dp;
    bool pali(string &s, int index , int i){
        if(dp[index][i] != -1) return dp[index][i];
        int l=index;
        int r=i;
        while(index<=i){
            if(s[index]!=s[i]){
                return dp[l][r]=false;
            }
            index++;
            i--;
        }
        return dp[l][r] = true;
    }
    void solve(int index,vector<string>path,string s)
    {
        if(index==s.size())
        {
            vct.push_back(path);
            return ;
        }
        for(int i=index;i<s.length();i++)
        {
            if(pali(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));

                solve(i+1,path,s);
                 path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        vector<string>path;
        solve(0,path,s);
        return vct;
    }
};