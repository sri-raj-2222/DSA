class Solution {
public:
    bool judgeCircle(string s) {
        int u=0,d=0,l=0,r=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='U') u++;
            else if(s[i]=='D') d++;
            else if(s[i]=='L') l++;
            else if(s[i]=='R') r++;
        }
        if(u==d && l==r) return 1;
        else return 0;
    }
};