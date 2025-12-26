class Solution {
public:
    int bestClosingTime(string s) {
        int y=0;
        int i=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='Y') y++;
        }
        int ans=INT_MAX,idx=0;
        for(int i=0;i<s.size();i++){
            if(y < ans){
                ans=y;
                idx=i;
            }
            cout<<y<<" ";
            if(s[i]=='Y') y--;
            else y++;
        }
        if(y < ans){
            idx=i;
        }
        return idx;
    }
};