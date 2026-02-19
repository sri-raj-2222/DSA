class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=1,ans=0,prev=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }
            else{
                ans+=min(prev,cnt);
                prev=cnt;
                cnt=1;
            }
        }
        ans+=min(prev,cnt);
        return ans;
    }
};