class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s[0]=='1' && s.size()==1) return 1;
        int cnt=0,one=0;
        for(int i=0;i<s.size();i++) if(s[i]=='1') one++;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1]){
                cnt++;
            }
        }
        if(cnt==0 && one > 0) return 1;
        if(cnt==1) return 1;
        else return 0;
    }
};