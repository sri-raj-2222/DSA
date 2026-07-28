class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        int n=s.size();
        int ind = 0;
        string str(n,'/0');
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                str[ind] = s[i];
                str[n-ind-1] = s[i];
                ind++;i++;
            }
            else{
                str[n/2] = s[i];
            }
        }
        if(str[n/2] == '0') str[n/2] = s[n-1];
        return str;
    }
};