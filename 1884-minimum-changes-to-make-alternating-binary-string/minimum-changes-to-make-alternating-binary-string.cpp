class Solution {
public:
    int minOperations(string s) {
        string str,strr;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                str.push_back('1');
                strr.push_back('0');
            }
            else{
                str.push_back('0');
                strr.push_back('1');
            }
        }
        int cnt=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(str[i]!=s[i]) cnt++;
            else if(strr[i]!=s[i]) cnt2++;
        }
        return min(cnt,cnt2);
    }
};