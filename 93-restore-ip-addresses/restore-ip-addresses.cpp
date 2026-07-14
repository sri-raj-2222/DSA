class Solution {
public:
    void solve(int i,string s,string str,vector<string> &ans,int dot){
        int n = s.size();
        if(i==n && dot < 0){
            ans.push_back(str);
            return ;
        }
        if(dot < 0 ||  i == n) return;
        int digit = s[i] - '0';
        string part="";
        int sum = 0;
        for(int j=i;j<min(i+3,n);j++){
            part+=s[j];
            sum = sum * 10 + (s[j] - '0');
            if(j > i && s[i] == '0') break;
            if(sum > 255) break;
            if(dot == 0){
                solve(j+1,s,str+part,ans,dot-1);
            }
            else{
                solve(j+1,s,str+part+'.',ans,dot-1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        string str;
        vector<string> ans;
        if(n < 4 || n > 12) return ans;
        solve(0,s,str,ans,3);
        return ans;
    }
};